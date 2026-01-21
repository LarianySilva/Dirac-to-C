%definição do escalar
s = 1 / sqrt(2);

%definição da matriz 2x2 de Hadamard

H = s * [1,1;1,-1];

%definição do estado |0>

qubit0=[1;0];

%produto matrcial

produto = H * qubit0;

%exibir

disp(produto);

%-----------------------------------------
%Aplicando a porta NOT (PAULI-x)
%------------------------------------------

%PORTA NOT
X = [0,1;1,0];

%aplicando a porta

resultadoX = X * produto;

disp("Resultado com a porta not aplicada:");
disp(resultadoX);


 %------------------------------------------------
 %com o inverso

 %invertendo |0> para |1>
passo1 = X * [1; 0];
%disp(passo1);

%aplicando Hadamard no estado |1>
resultado_inverso = H * passo1 ;

disp("H * (X * |0>):");
disp(resultado_inverso);
%-----------------------------------------------
disp("------------------------------------------");


%---------------------------------------------------
%aplicando o hadamard denovo

estado2 = H * produto;

%ver 1 e 0

resultadoF = round(estado2);

disp("Estado inicial era |0>. Após H*H, o resultado é:");
disp(resultadoF);


