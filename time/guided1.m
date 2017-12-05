function guided1
clear all;
close all;
hold on;

x = [1 2 4 8 16];

t0 = [ 5.937296 3.396720 2.190465 1.868807 2.267183 ];
plot(x, t0, 'LineWidth', 3, 'DisplayName', 'models/ironman.obj 3840x2160');

title('hpc-class');
xlabel('Number of Threads');
ylabel('Render Time');
legend('show', 'Location', 'NorthWest');

