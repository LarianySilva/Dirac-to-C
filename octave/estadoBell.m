%Utilizando CNOT E 2 QUBTS

%Dados necessários
H = (1/sqrt(2))*[1,1;1,-1];

I = eye(2); %matriz identidade
X =  [0,1;1,0];%porta NOT
q0= [1;0];

%resultado inicial |00> (produto de Kronecker)
psi_in = kron(q0,q0);

%disp(psi_in);

%aplicação do H no primeiro qubit
H_EX = kron(H,I);
psi_m = H_EX * psi_in;

%--------------------------
%disp(H_EX);
%disp(psi_m);
%--------------------------

%CNOT

CNOT = [1,0,0,0;0,1,0,0;0,0,0,1;0,0,1,0];

%emanharamento

estadoB = CNOT * psi_m;

disp("Estado Bell:");
disp(estadoB);

prob = abs(estadoB).^2;
disp(prob)

%-------------------------------------------------------------

%função sort

sort = rand();

%colapso
%50% = 00 || 50% =11

if sort <= prob(1)
  resultado_medicao = "00";
else
  resultado_medicao = "11";
end

fprintf('número do sortei: %f\n',sort);
fprintf('Resultado da medição:%s\n',resultado_medicao);
%------------------------------------------------------------------

cont_00 = 0;
cont_11 = 0;

for i = 1:1000
    if rand() <= 0.5
        cont_00++;
    else
        cont_11++;
    end
end

disp(['Em 1000 medidas, obtivemos:']);
disp(['|00>: ', num2str(cont_00)]);
disp(['|11>: ', num2str(cont_11)]);

