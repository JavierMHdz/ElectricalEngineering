%{
Javier Macossay
ITP 168 - Fall 2015
Lab 10
macossay@usc.edu
Revision History
Date            Changes             Programmer
----------------------------------------------------
10/1/2015        Original            Javier Macossay
%}


validInput = false;
while (~validInput)
    numContacts = input('Enter intial number of contacts: ');
    if (numContacts > 0)
        validInput = true;
    else
        fprintf('You must creat at least one contact!\n');
    end;
end;

%know numContacts is at least 1
contact = struct('last',[],'first',[],'phone',[],'ID',[]);

contact = repmat(contact,1,numContacts);

%fill them with stuff
for index = 1:numContacts
    contact(index).last = input('Last Name: ','s');
    contact(index).first = input('First Name: ','s');
    contact(index).phone = input('PH: ');
    contact(index).ID = index;
end;

%present my menu and do stuff
keepGoing = true;
while (keepGoing)
    numContacts = length(contact);
    fprintf('Choose from the following options:\n');
    fprintf('\t1. Print Contact\n');
    fprintf('\t2. Add Contact\n');
    fprintf('\t3. Delete Contact\n');
    fprintf('\t4. Quit\n');
    choice = input('Choose: ');
    
    %switch on choice
    switch choice
        case 1  %print contact list
            if (numContacts > 0)
                for index = 1:numContacts
                    fprintf('%.0f. %s\n%.0f\n',contact(index).ID,contact(index).first,contact(index).phone);
                end;
            else
                fprintf('No Contacts to print!\n');
            end;
        case 2  %add contact
            contact(numContacts + 1).last = input('Last Name: ','s');
            contact(numContacts + 1).first = input('First Name: ','s');
            contact(numContacts + 1).phone = input('PH: ');
            contact(numContacts + 1).ID = numContacts + 1;
        case 3 %delete contact
            if (numContacts > 0)
                for index = 1:numContacts
                    fprintf('%0.f %s, %s\n', contact(index).ID, contact(index).last, contact(index.first));
                end;
                while (true)
                    userIn = input('Please choose and ID: ');
                    if(userIn >= 1 && userIn <= numContacs)
                        break;
                    else
                        fprintf('Invalid ID!\n');
                    end;
                end;
                contact(userIn) = [];
                
                for index = 1:(numContacts -1)
                    contact(index).ID = index;
                end;
            else
            end;
        case 4
            
            keepGoing = false;
            fprintf('Quitting!\n');
        otherwise
            fprintf('Invalid option!\n');
    end;
end;
    