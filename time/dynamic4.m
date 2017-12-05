function dynamic4
clear all;
close all;
hold on;

x = [1 2 4 8 16];

t0 = [ 6.283623 3.586096 2.277317 1.646120 1.478188 ];
plot(x, t0, 'LineWidth', 3, 'DisplayName', 'models/ironman.obj 3840x2160');

title('hpc-class');
xlabel('Number of Threads');
ylabel('Render Time');
legend('show', 'Location', 'NorthWest');

