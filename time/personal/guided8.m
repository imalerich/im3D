function guided8
clear all;
close all;
hold on;

x = [1 2 4 8 16];

t0 = [ 2.092850 1.261323 0.817261 0.986027 7.041624 ];
plot(x, t0, 'LineWidth', 3, 'DisplayName', 'models/ironman.obj 3840x2160');

title('Personal');
xlabel('Number of Threads');
ylabel('Render Time');
legend('show', 'Location', 'NorthWest');

