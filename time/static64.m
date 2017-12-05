function static64
clear all;
close all;
hold on;

x = [1 2 4 8 16];

t0 = [ 5.957563 3.396595 2.342645 1.841425 1.891801 ];
plot(x, t0, 'LineWidth', 3, 'DisplayName', 'models/ironman.obj 3840x2160');

title('hpc-class');
xlabel('Number of Threads');
ylabel('Render Time');
legend('show', 'Location', 'NorthWest');

