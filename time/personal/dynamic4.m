function dynamic4
clear all;
close all;
hold on;

x = [1 2 4 8 16];

t0 = [ 2.396339 1.526432 0.965712 0.907712 6.855692 ];
plot(x, t0, 'LineWidth', 3, 'DisplayName', 'models/ironman.obj 3840x2160');

title('Personal');
xlabel('Number of Threads');
ylabel('Render Time');
legend('show', 'Location', 'NorthWest');

