clear
clc
close all
format compact
%
x = linspace(0,10,100);
y = x.^2;
a = 0:0.1:10;
b = 10*a;
% plotting
figure(1)
plot(x,y,a,b)
title('Sample plot')
xlabel('x, a')
ylabel('y, b')
grid on
legend('y = x^2','b = 10*a','Location','best')