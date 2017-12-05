function static8
clear all;
close all;
hold on;

x = [1 2 4 8 16];

t0 = [ 6.019858 3.330946 2.069536 1.369063 1.266668 ];
plot(x, t0, 'LineWidth', 3, 'DisplayName', 'models/ironman.obj 3840x2160');

title('hpc-class');
xlabel('Number of Threads');
ylabel('Render Time');
legend('show', 'Location', 'NorthWest');

