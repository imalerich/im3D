function static1
clear all;
close all;
hold on;

x = [1 2 4 8 16];

t0 = [ 5.993472 3.328531 2.053528 1.354964 1.217735 ];
plot(x, t0, 'LineWidth', 3, 'DisplayName', 'models/ironman.obj 3840x2160');

title('hpc-class');
xlabel('Number of Threads');
ylabel('Render Time');
legend('show', 'Location', 'NorthWest');

