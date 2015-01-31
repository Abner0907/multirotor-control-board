function [ outputVektor ] = firstOrder( inputVektor, dt, P )

    outputVektor(1, 1) = 0;
    
    for i = 2:1:length(inputVektor)
        outputVektor(i, 1) = outputVektor(i-1)*dt(i)*P(1) + inputVektor(i)*dt(i)*P(2);
    end

end
