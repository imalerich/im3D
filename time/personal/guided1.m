function guided1
clear all;
close all;
hold on;

x = [1 2 4 8 16];

t0 = [ 2.234987 1.355025 0.864444 1.050368 7.717989 ];
plot(x, t0, 'LineWidth', 3, 'DisplayName', 'models/ironman.obj 3840x2160');

title('Personal');
xlabel('Number of Threads');
ylabel('Render Time');
legend('show', 'Location', 'NorthWest');

