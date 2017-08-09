% net = newff([0 10;0 10;0 10;0 6; 0 6; 0 6],[10 1],{'tansig','purelin'});
%  net = newff([0 10;0 10;0 10;0 6; 0 6; 0 6],[10 5 1],{'tansig','tansig','purelin'});
% net = newff([42 60;42 60;42 60;42 60;42 60;42 60; 42 60; 42 60],[10 1],{'tansig','purelin'});

% Nst Ps Pd
net = newff([13500 22500;30 55;40 160],[10 1],{'tansig','purelin'});
% net = newff([13500 22500;30 55;40 160],[10 5 1],{'tansig', 'tansig','purelin'});

s = [N1';Ps1';Pd1'];
%s = [u';u1';u2'];
%s = [u';u1';u2'];

net.trainParam.epochs=5000;
%net.trainParam.show=50;
net.trainParam.goal=0.00005
net = train(net,s,Q1');
gensim(net,-1);