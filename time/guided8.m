function guided8
clear all;
close all;
hold on;

x = [1 2 4 8 16];

t0 = [ 5.933393 3.392965 2.162468 1.621884 1.578440 ];
plot(x, t0, 'LineWidth', 3, 'DisplayName', 'models/ironman.obj 3840x2160');

title('hpc-class');
xlabel('Number of Threads');
ylabel('Render Time');
legend('show', 'Location', 'NorthWest');

