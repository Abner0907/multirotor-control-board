function [ states, covariance ] = kalman( states, covariance, measurement, u, A, B)
    
%% support matrices

% �um procesu
R = diag([1, 1, 1]);


if (size(measurement, 1) == 1)

    % �um m��en�
    Q = diag([100]);
    
    C = [0, 1, 0];
else
     
    % �um m��en�
    Q = diag([0.058^2, 1000]);
    
    C = [1, 0, 0, 0, 0;
         0, 1, 0, 0, 0];
end

%% Krok predikce

states = A*states + B*u;

covariance = A*covariance*A' + R;

%% Krok korekce 

K = covariance*C'*((C*covariance*C' + Q)^-1);

states = states + K*(measurement - C*states);
covariance = (eye(3) - K*C)*covariance;

end

