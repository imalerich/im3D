function static1
clear all;
close all;
hold on;

x = [1 2 4 8 16];

t0 = [ 2.229347 1.274496 0.837284 0.873060 7.448848 ];
plot(x, t0, 'LineWidth', 3, 'DisplayName', 'models/ironman.obj 3840x2160');

title('Personal');
xlabel('Number of Threads');
ylabel('Render Time');
legend('show', 'Location', 'NorthWest');

