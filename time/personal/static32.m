function static32
clear all;
close all;
hold on;

x = [1 2 4 8 16];

t0 = [ 2.096299 1.191206 0.755017 0.858247 7.106753 ];
plot(x, t0, 'LineWidth', 3, 'DisplayName', 'models/ironman.obj 3840x2160');

title('Personal');
xlabel('Number of Threads');
ylabel('Render Time');
legend('show', 'Location', 'NorthWest');

