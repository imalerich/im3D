function static
clear all;
close all;
hold on;

x = [1 2 4 8 16];

t0 = [ 5.962850 3.514727 2.288855 1.501498 1.304261 ];
plot(x, t0, 'LineWidth', 3, 'DisplayName', 'models/ironman.obj 3840x2160');

title('hpc-class');
xlabel('Number of Threads');
ylabel('Render Time');
legend('show', 'Location', 'NorthWest');

