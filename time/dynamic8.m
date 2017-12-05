function dynamic8
clear all;
close all;
hold on;

x = [1 2 4 8 16];

t0 = [ 6.147951 3.464589 2.200541 1.576933 1.395637 ];
plot(x, t0, 'LineWidth', 3, 'DisplayName', 'models/ironman.obj 3840x2160');

title('hpc-class');
xlabel('Number of Threads');
ylabel('Render Time');
legend('show', 'Location', 'NorthWest');

