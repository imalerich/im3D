function method3
clear all;
close all;
hold on;

x = [1 2 4 8 16];

t0 = [ 5.926842 3.821624 2.380739 6.894392 11.582861 ];
plot(x, t0, 'LineWidth', 3, 'DisplayName', 'models/ironman.obj 3840x2160');

title('Personal');
xlabel('Number of Threads');
ylabel('Render Time');
legend('show', 'Location', 'NorthWest');

