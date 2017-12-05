function static32
clear all;
close all;
hold on;

x = [1 2 4 8 16];

t0 = [ 5.973761 3.290060 2.147081 1.576057 1.543994 ];
plot(x, t0, 'LineWidth', 3, 'DisplayName', 'models/ironman.obj 3840x2160');

title('hpc-class');
xlabel('Number of Threads');
ylabel('Render Time');
legend('show', 'Location', 'NorthWest');

