function guided4
clear all;
close all;
hold on;

x = [1 2 4 8 16];

t0 = [ 5.933095 3.405738 2.162900 1.678488 1.761131 ];
plot(x, t0, 'LineWidth', 3, 'DisplayName', 'models/ironman.obj 3840x2160');

title('hpc-class');
xlabel('Number of Threads');
ylabel('Render Time');
legend('show', 'Location', 'NorthWest');

