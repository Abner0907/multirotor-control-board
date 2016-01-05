if exist('s')
    fclose(s);
    delete(s);
    clear s;
end

clear all

s = serial('COM19');
s.BaudRate = 115200;
s.BytesAvailableFcnMode = 'terminator';
s.Terminator = 'CR/LF';
s.DataBits = 8;
s.Parity = 'none';
s.StopBits = 1;

fopen(s);
pos = 2;

% receeding horizon length
horizon_length = 100;

in(1:horizon_length, 1:4) = 0;

figure(11);

numBlobs = 6;
blobx = 7;
bloby = 8;
blobz = 9;

magx = 10;
magy = 11;
magz = 12;

plotSize = 3;

while true
    
    % request data from a helicopter        
    fprintf(s, '%c', 'b');
    
    % wait for data       
    while (s.BytesAvailable <= 0)
    end

    in(pos, 1) = fread(s, 1, 'single');
    in(pos, 2) = fread(s, 1, 'single');
    in(pos, 3) = fread(s, 1, 'single');
    in(pos, 4) = fread(s, 1, 'single');
    
    in(pos, 5) = fread(s, 1, 'uint8');
    
%     blob
    in(pos, blobx) = fread(s, 1, 'single');
    in(pos, bloby) = fread(s, 1, 'single');
    in(pos, blobz) = fread(s, 1, 'single');
    [in(pos, blobx) in(pos, bloby) in(pos, blobz)]
    
%     magnetometer
%     in(pos, magx) = fread(s, 1, 'int16');
%     in(pos, magy) = fread(s, 1, 'int16');
%     in(pos, magz) = fread(s, 1, 'int16');
%     [in(pos, magx) in(pos, magy) in(pos, magz)]
    
    % read line ending     
    fread(s, 1, 'int16');
    
    % plot the position     
    subplot(2, 1, 1);
    hold off
    scatter(-in(pos, 2), in(pos, 1), 'filled');
    hold on
    scatter(-in(pos, 4), in(pos, 3), 'filled', 'r');
    circle(-in(pos, bloby)-in(pos, 2), in(pos, blobx)+in(pos, 1), 0.1);
    axis([-plotSize-in(pos, 2) plotSize-in(pos, 2) -plotSize+in(pos, 1) plotSize+in(pos, 1)]);
    
    % plot the action
    subplot(2, 1, 2);
    hold off
    plot(in([pos:end 1:pos-1], 5), 'b');
    hold on
    plot(in([pos:end 1:pos-1], 6), 'r');
    axis([0 horizon_length -850 850]);
    
    %     if (controllerEnabled == 1)
%         text(.5,.5,['\fontsize{16}\color{green}Zapnuto ']);
%     else
%         text(.5,.5,['\fontsize{16}\color{red}Vypnuto ']);
%     end
%     text(.1,0,['\fontsize{16}��zen� 2. �rovn�: ']);
%     if (positionControllerEnabled == 1)
%         text(.5,0,['\fontsize{16}\color{green}Zapnuto ']);
%     else
%         text(.5,0,['\fontsize{16}\color{red}Vypnuto ']);
%     end
% 
%     if (landing == 1)
%         text(.1,-0.5,['\fontsize{16}\color{green}P�ist�n� ']);
%     end
%     
%     if (trajectory == 1)
%         text(.1,-0.5,['\fontsize{16}\color{green}Trajektorie ']);
%     end
%     if (gumstix == 1)
%         text(.5,-0.5,['\fontsize{16}\color{green}Gumstix ']);
%     end
%     axis([0 0.8 -1 1]);

    drawnow;

    pos = pos + 1;
    if (pos == (horizon_length+1))
       pos = 1; 
    end
    
end

