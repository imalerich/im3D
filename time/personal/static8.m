function static8
clear all;
close all;
hold on;

x = [1 2 4 8 16];

t0 = [ 2.163130 1.234190 0.776501 0.997283 7.214013 ];
plot(x, t0, 'LineWidth', 3, 'DisplayName', 'models/ironman.obj 3840x2160');

title('Personal');
xlabel('Number of Threads');
ylabel('Render Time');
legend('show', 'Location', 'NorthWest');

