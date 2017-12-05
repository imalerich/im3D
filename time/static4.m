function static4
clear all;
close all;
hold on;

x = [1 2 4 8 16];

t0 = [ 6.025800 3.281866 2.051981 1.359764 1.215193 ];
plot(x, t0, 'LineWidth', 3, 'DisplayName', 'models/ironman.obj 3840x2160');

title('hpc-class');
xlabel('Number of Threads');
ylabel('Render Time');
legend('show', 'Location', 'NorthWest');

