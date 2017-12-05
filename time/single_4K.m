function single_4K
clear all;
close all;
hold on;

x = [1 2 4 8 16];

t0 = [ 4.571170 2.807682 5.390312 5.926197 ];
plot(x, t0, 'LineWidth', 3, 'DisplayName', 'models/ironman.obj 3840x2160');

title('hpc-class');
xlabel('Number of Threads');
ylabel('Render Time');
legend('show', 'Location', 'NorthWest');

