function static64
clear all;
close all;
hold on;

x = [1 2 4 8 16];

t0 = [ 2.086788 1.213297 0.885825 1.547635 7.359226 ];
plot(x, t0, 'LineWidth', 3, 'DisplayName', 'models/ironman.obj 3840x2160');

title('Personal');
xlabel('Number of Threads');
ylabel('Render Time');
legend('show', 'Location', 'NorthWest');

