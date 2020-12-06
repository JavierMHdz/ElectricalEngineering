function varargout = sinsum(varargin)
% SINSUM Application M-file for sinsum.fig
%    FIG = SINSUM launch sinsum GUI.
%    SINSUM('callback_name', ...) invoke the named callback.
%
% To execute with "alternative" matching-functions, call "sinsum(n)" where n is:
%   0 --  Sawtooth wave (Default)
%   1 --  Square wave
%   2 --  Dirichlet function
%   3 --  "Parabolic" wave

% Last Modified by GUIDE v2.0 01-Feb-2002 14:41:23

% Written by Mark Bartsch, Winter 2002
% Modification History:
%    8/16/02  --  Added modification history (MB)


if nargin == 0 | ~ischar(varargin{1}) % LAUNCH GUI

    set(0,'ShowHiddenHandles','On')
    h = findobj('Name','SinSum');
    if ~isempty(h)
        close(h);
    end
    set(0,'ShowHiddenHandles','Off');

    fig = openfig(mfilename,'reuse');

    % Use system color scheme for figure:
    set(fig,'Color',get(0,'defaultUicontrolBackgroundColor'));

    % Generate a structure of handles to pass to callbacks, and store it. 
    handles = guihandles(fig);
    
    handles.mode = 0;
    handles.fs = 1000;
    handles.t = (0:1/handles.fs:1)';
    handles.amps = [1/2 1/4 1/8];
    handles.phases = [0 pi/6 pi/4];
    handles.frqs = [2 4 6]*2*pi;
    handles.data = [handles.amps(1)*cos(handles.t*handles.frqs(1) + handles.phases(1)), ...
         handles.amps(2)*cos(handles.t*handles.frqs(2) + handles.phases(2)), ...
         handles.amps(3)*cos(handles.t*handles.frqs(3) + handles.phases(3))];
    handles.data(:,4) = sum(handles.data,2);

    % This defines the signal to match
    if nargin < 1 | varargin{1} == 0
        handles.data(:,5) = 2*sawtooth(handles.t*2*2*pi + pi);
    elseif varargin{1} == 1
        handles.data(:,5) = 1.5*square(handles.t*2*2*pi + pi);
    elseif varargin{1} == 2
        handles.data(:,5) = 2*diric(handles.t*2*2*pi + pi,9);
        handles.data(:,5) = handles.data(:,5) - mean(handles.data(:,5));        
    elseif varargin{1} == 3
        handles.data(:,5) = (mod(handles.t,1/2)*4 - .6).^2;
        handles.data(:,5) = handles.data(:,5) - mean(handles.data(:,5));        
    end
    
    set(fig,'HandleVisibility','On');

    pause(.01);
    axes(handles.axes1);
    h = plot(handles.t,handles.data(:,[5 4 1 2 3]));
    axis([min(handles.t) max(handles.t) -2 2]);
    h = h([3 4 5 2 1]);
    handles.data_h = h;
    set(h(1),'Color',[1 0 0],'LineStyle',':','EraseMode','xor');
    set(h(1),'ButtonDownFcn',sprintf('sinsum(''plot_select'',gcbo,1,guidata(gcbo));'));
    set(h(2),'Color',[0 1 0],'LineStyle',':','EraseMode','xor');
    set(h(2),'ButtonDownFcn',sprintf('sinsum(''plot_select'',gcbo,2,guidata(gcbo));'));
    set(h(3),'Color',[0 0 1],'LineStyle',':','EraseMode','xor');
    set(h(3),'ButtonDownFcn',sprintf('sinsum(''plot_select'',gcbo,3,guidata(gcbo));'));
    set(h(4),'Color',[0 0 0],'LineStyle','--','EraseMode','xor');
    set(h(5),'Color',[0 0 0],'LineStyle','-','EraseMode','xor');

    set(handles.amp1,'String',num2str(handles.amps(1)));
    set(handles.amp2,'String',num2str(handles.amps(2)));
    set(handles.amp3,'String',num2str(handles.amps(3)));
    set(handles.phase1,'String',num2str(handles.phases(1)));
    set(handles.phase2,'String',num2str(handles.phases(2)));
    set(handles.phase3,'String',num2str(handles.phases(3)));
    
    mse = mean(diff(handles.data(:,4:5),[],2).^2);
    set(handles.mse,'String',num2str(mse));
    
    set(fig,'HandleVisibility','Callback');
  
    guidata(fig, handles);

    if nargout > 0
        varargout{1} = fig;
    end

elseif ischar(varargin{1}) % INVOKE NAMED SUBFUNCTION OR CALLBACK

    try
        if (nargout)
            [varargout{1:nargout}] = feval(varargin{:}); % FEVAL switchyard
        else
            feval(varargin{:}); % FEVAL switchyard
        end
    catch
        disp(lasterr);
    end

end


%| ABOUT CALLBACKS:
%| GUIDE automatically appends subfunction prototypes to this file, and 
%| sets objects' callback properties to call them through the FEVAL 
%| switchyard above. This comment describes that mechanism.
%|
%| Each callback subfunction declaration has the following form:
%| <SUBFUNCTION_NAME>(H, EVENTDATA, HANDLES, VARARGIN)
%|
%| The subfunction name is composed using the object's Tag and the 
%| callback type separated by '_', e.g. 'slider2_Callback',
%| 'figure1_CloseRequestFcn', 'axis1_ButtondownFcn'.
%|
%| H is the callback object's handle (obtained using GCBO).
%|
%| EVENTDATA is empty, but reserved for future use.
%|
%| HANDLES is a structure containing handles of components in GUI using
%| tags as fieldnames, e.g. handles.figure1, handles.slider2. This
%| structure is created at GUI startup using GUIHANDLES and stored in
%| the figure's application data using GUIDATA. A copy of the structure
%| is passed to each callback.  You can store additional information in
%| this structure at GUI startup, and you can change the structure
%| during callbacks.  Call guidata(h, handles) after changing your
%| copy to replace the stored original so that subsequent callbacks see
%| the updates. Type "help guihandles" and "help guidata" for more
%| information.
%|
%| VARARGIN contains any extra arguments you have passed to the
%| callback. Specify the extra arguments by editing the callback
%| property in the inspector. By default, GUIDE sets the property to:
%| <MFILENAME>('<SUBFUNCTION_NAME>', gcbo, [], guidata(gcbo))
%| Add any extra arguments after the last argument, before the final
%| closing parenthesis.



% --------------------------------------------------------------------
function varargout = axes1_ButtonDownFcn(h, eventdata, handles, varargin)


% --------------------------------------------------------------------
function varargout = figure1_CreateFcn(h, eventdata, handles, varargin)


% --------------------------------------------------------------------
function varargout = plot_select(h,eventdata,handles,varargin);

pt = get(handles.axes1,'currentpoint');
pt = pt(1,1:2);
handles.mode = 1;
handles.move_plot = eventdata;
handles.xref = pt(1);
handles.yref = pt(2);
guidata(gcf, handles);




% --------------------------------------------------------------------
function varargout = figure1_WindowButtonMotionFcn(h, eventdata, handles, varargin)

if handles.mode == 1
    pt = get(handles.axes1,'currentpoint');
    pt = pt(1,1:2);
    
    mvplt = handles.move_plot;
    if handles.amps(mvplt) == 0
        newA = pt(2);
        newP = -pt(1)*handles.frqs(mvplt);
    else
        newA = handles.amps(mvplt)*(pt(2)/handles.yref);
        newP = handles.phases(mvplt) + (handles.xref-pt(1))*handles.frqs(mvplt);
    end

    if newA < 0
        newA = -newA;
        newP = newP + pi;
    end
    
    newP = mod(newP,2*pi);

    handles.newA = newA;
    handles.newP = newP;
    
    eval(['set(handles.amp' num2str(mvplt) ',''String'',num2str(newA));']);
    eval(['set(handles.phase' num2str(mvplt) ',''String'',num2str(newP));']);
    mse = mean(diff(handles.data(:,4:5),[],2).^2);
    set(handles.mse,'String',num2str(mse));
    
    handles.data(:,mvplt) = newA*cos(handles.t*handles.frqs(mvplt) + newP);
    handles.data(:,4) = sum(handles.data(:,1:3),2);
    set(handles.data_h(mvplt),'YData',handles.data(:,mvplt));
    set(handles.data_h(4),'YData',handles.data(:,4));
end

guidata(gcf, handles);



% --------------------------------------------------------------------
function varargout = figure1_WindowButtonUpFcn(h, eventdata, handles, varargin)

    
if handles.mode == 1
    handles.mode = 0;

    handles.amps(handles.move_plot) = handles.newA;
    handles.phases(handles.move_plot) = handles.newP;
end

guidata(gcf, handles);



% --------------------------------------------------------------------
function varargout = amp1_Callback(h, eventdata, handles, varargin)

mvplt = 1;
newA = eval(get(h,'String'),'[]');
if isempty(newA)
    set(h,'String',num2str(handles.amps(mvplt)));
else
    newP = handles.phases(mvplt);
    if newA < 0
        newA = -newA;
        newP = mod(newP+pi,2*pi);
    end
    handles.amps(mvplt) = newA;
    handles.phases(mvplt) = newP;
    eval(['set(handles.amp' num2str(mvplt) ',''String'',num2str(newA));']);
    eval(['set(handles.phase' num2str(mvplt) ',''String'',num2str(newP));']);
    
    handles.data(:,mvplt) = newA*cos(handles.t*handles.frqs(mvplt) + newP);
    handles.data(:,4) = sum(handles.data(:,1:3),2);
    set(handles.data_h(mvplt),'YData',handles.data(:,mvplt));
    set(handles.data_h(4),'YData',handles.data(:,4));

    mse = mean(diff(handles.data(:,4:5),[],2).^2);
    set(handles.mse,'String',num2str(mse));
    
    guidata(gcf, handles);
end


% --------------------------------------------------------------------
function varargout = phase1_Callback(h, eventdata, handles, varargin)

mvplt = 1;
newP = eval(get(h,'String'),'[]');
if isempty(newP)
    set(h,'String',num2str(handles.phases(mvplt)));
else
    newA = handles.amps(mvplt);
    newP = mod(newP,2*pi);
    handles.phases(mvplt) = newP;
    eval(['set(handles.amp' num2str(mvplt) ',''String'',num2str(newA));']);
    eval(['set(handles.phase' num2str(mvplt) ',''String'',num2str(newP));']);
    
    handles.data(:,mvplt) = newA*cos(handles.t*handles.frqs(mvplt) + newP);
    handles.data(:,4) = sum(handles.data(:,1:3),2);
    set(handles.data_h(mvplt),'YData',handles.data(:,mvplt));
    set(handles.data_h(4),'YData',handles.data(:,4));

    mse = mean(diff(handles.data(:,4:5),[],2).^2);
    set(handles.mse,'String',num2str(mse));
    
    guidata(gcf, handles);
end



% --------------------------------------------------------------------
function varargout = amp2_Callback(h, eventdata, handles, varargin)

mvplt = 2;
newA = eval(get(h,'String'),'[]');
if isempty(newA)
    set(h,'String',num2str(handles.amps(mvplt)));
else
    newP = handles.phases(mvplt);
    if newA < 0
        newA = -newA;
        newP = mod(newP+pi,2*pi);
    end
    handles.amps(mvplt) = newA;
    handles.phases(mvplt) = newP;
    eval(['set(handles.amp' num2str(mvplt) ',''String'',num2str(newA));']);
    eval(['set(handles.phase' num2str(mvplt) ',''String'',num2str(newP));']);
    
    handles.data(:,mvplt) = newA*cos(handles.t*handles.frqs(mvplt) + newP);
    handles.data(:,4) = sum(handles.data(:,1:3),2);
    set(handles.data_h(mvplt),'YData',handles.data(:,mvplt));
    set(handles.data_h(4),'YData',handles.data(:,4));

    mse = mean(diff(handles.data(:,4:5),[],2).^2);
    set(handles.mse,'String',num2str(mse));
    
    guidata(gcf, handles);
end



% --------------------------------------------------------------------
function varargout = phase2_Callback(h, eventdata, handles, varargin)

mvplt = 2;
newP = eval(get(h,'String'),'[]');
if isempty(newP)
    set(h,'String',num2str(handles.phases(mvplt)));
else
    newA = handles.amps(mvplt);
    newP = mod(newP,2*pi);
    handles.phases(mvplt) = newP;
    eval(['set(handles.amp' num2str(mvplt) ',''String'',num2str(newA));']);
    eval(['set(handles.phase' num2str(mvplt) ',''String'',num2str(newP));']);
    
    handles.data(:,mvplt) = newA*cos(handles.t*handles.frqs(mvplt) + newP);
    handles.data(:,4) = sum(handles.data(:,1:3),2);
    set(handles.data_h(mvplt),'YData',handles.data(:,mvplt));
    set(handles.data_h(4),'YData',handles.data(:,4));

    mse = mean(diff(handles.data(:,4:5),[],2).^2);
    set(handles.mse,'String',num2str(mse));
    
    guidata(gcf, handles);
end



% --------------------------------------------------------------------
function varargout = amp3_Callback(h, eventdata, handles, varargin)

mvplt = 3;
newA = eval(get(h,'String'),'[]');
if isempty(newA)
    set(h,'String',num2str(handles.amps(mvplt)));
else
    newP = handles.phases(mvplt);
    if newA < 0
        newA = -newA;
        newP = mod(newP+pi,2*pi);
    end
    handles.amps(mvplt) = newA;
    handles.phases(mvplt) = newP;
    eval(['set(handles.amp' num2str(mvplt) ',''String'',num2str(newA));']);
    eval(['set(handles.phase' num2str(mvplt) ',''String'',num2str(newP));']);
    
    handles.data(:,mvplt) = newA*cos(handles.t*handles.frqs(mvplt) + newP);
    handles.data(:,4) = sum(handles.data(:,1:3),2);
    set(handles.data_h(mvplt),'YData',handles.data(:,mvplt));
    set(handles.data_h(4),'YData',handles.data(:,4));

    mse = mean(diff(handles.data(:,4:5),[],2).^2);
    set(handles.mse,'String',num2str(mse));
    
    guidata(gcf, handles);
end



% --------------------------------------------------------------------
function varargout = phase3_Callback(h, eventdata, handles, varargin)

mvplt = 3;
newP = eval(get(h,'String'),'[]');
if isempty(newP)
    set(h,'String',num2str(handles.phases(mvplt)));
else
    newA = handles.amps(mvplt);
    newP = mod(newP,2*pi);
    handles.phases(mvplt) = newP;
    eval(['set(handles.amp' num2str(mvplt) ',''String'',num2str(newA));']);
    eval(['set(handles.phase' num2str(mvplt) ',''String'',num2str(newP));']);
    
    handles.data(:,mvplt) = newA*cos(handles.t*handles.frqs(mvplt) + newP);
    handles.data(:,4) = sum(handles.data(:,1:3),2);
    set(handles.data_h(mvplt),'YData',handles.data(:,mvplt));
    set(handles.data_h(4),'YData',handles.data(:,4));

    mse = mean(diff(handles.data(:,4:5),[],2).^2);
    set(handles.mse,'String',num2str(mse));
    
    guidata(gcf, handles);
end



% --------------------------------------------------------------------
function varargout = pushbutton1_Callback(h, eventdata, handles, varargin)

print -dbitmap


% --------------------------------------------------------------------
function varargout = pushbutton2_Callback(h, eventdata, handles, varargin)

printdlg -crossplatform
