function static128
clear all;
close all;
hold on;

x = [1 2 4 8 16];

t0 = [ 5.951189 3.550487 2.671375 2.297013 2.460522 ];
plot(x, t0, 'LineWidth', 3, 'DisplayName', 'models/ironman.obj 3840x2160');

title('hpc-class');
xlabel('Number of Threads');
ylabel('Render Time');
legend('show', 'Location', 'NorthWest');

