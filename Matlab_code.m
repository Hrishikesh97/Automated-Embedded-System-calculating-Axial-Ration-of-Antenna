
% TCPIP0::192.168.153.79::inst0::INSTR
clc;
clear all;
close all;
% ipFF = '192.168.153.79';
FF = tcpip('10.61.153.79',5025);
FF.InputBufferSize = 8388608;
% FF = visa('agilent', 'TCPIP0::192.168.164.100::inst0::INSTR');
% Now we try to connect to the Fieldfox
try
fopen(FF);
msgbox('Connecting to Agilent Fieldfox was successful');
catch
errordlg('Can not connect to Agilent FieldFox. Check connections and network settings');
return;
end

% If successfully connecting to Fieldfox,
% we can now send remote control commands (SCPI)
% using the fprintf() command ...
% query() command can also be used and is
% equivalent to the combined fprintf() and fscanf() commands
response1= query(FF, '*IDN?');
response1;
%%
% fopen(FF);
%fprintf(FF, sprintf(':INSTrument:SELect "%s"', 'SA'));
%fprintf(FF, sprintf(':CALCulate:PARameter1:DEFine %s', 'power'));
X = 360;
%fprintf(FF, sprintf(':SENSe:SWEep:POINts %d', X));
% repeat LOOP
a = 401;
h(1,1)=0;
for i =2:1:a;
 %   fprintf(FF, sprintf(':INITiate:CONTinuous %d', 0));
 %  fprintf(FF, ':INITiate:IMMediate');
 %   fprintf(FF, '*WAI');
    fileID = fopen('test.txt','r');
    formatSpec = '%f';
B = fscanf(fileID,formatSpec);    
h(1,i)= B ;
response2= query(FF, 'CALC:MARK:Y?');
q = str2double(response2);
%h(2,i)= q;

    while(h(1,i) == h(1,i-1))
      %  tID3 = fopen('feedback.txt','w');
       % fprintf(tID3,'%s','WAIT');
        %fclose(tID3);
        1;
    end
    
  %  while(h(1,i) ~= h(1,i-1))
        tID3 = fopen('feedback.txt','w');
        fprintf(tID3,'%s','WAIT');
        fclose(tID3);
        pause(2.5322345878787);
        h(2,i) = q;
        tID2 = fopen('feedback.txt','w');
        fprintf(tID3,'%s','GO');
        fclose(tID2);
        x(i) = h(1,i);
        y(i) = h(2,i);
        plot(x,y);
%    end    
h(1,i)
h(2,i)




%fileID1 = fopen('measure.txt','w');
%fprintf(fileID1,'%6s %12s\n\n','degree','dBm');
% fileID1 = fopen('measure.txt','w');
% fprintf(fileID1,'%6s %12s\n','degree','dBm');
% fprintf(fileID1,'%6.2f %12.8f\n',A);
% fclose(fileID1);
%title('axial ratio-polarization');
%xlabel('degree');
%ylabel('dB');
% provides delay for 10sec
pause(1);
% Clean up all objects.
%clear FF;
fclose all;
% provides delay for 10sec
pause(1);

%end for loop
end

tID1 = fopen('h.txt','w');
%fprintf(tID1,'%6s %12s\n','d','r');
fprintf(tID1,'%6.2f %12.8f\n',h);
fclose(tID1);

% fclose(FF);
% additional clean up procedures
% deleting the interface object variable used
% and removing it from the workspace
%delete(FF)