function static4
clear all;
close all;
hold on;

x = [1 2 4 8 16];

t0 = [ 2.259926 1.298466 0.765203 0.784985 7.189409 ];
plot(x, t0, 'LineWidth', 3, 'DisplayName', 'models/ironman.obj 3840x2160');

title('Personal');
xlabel('Number of Threads');
ylabel('Render Time');
legend('show', 'Location', 'NorthWest');

