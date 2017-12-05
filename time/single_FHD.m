function single_FHD
clear all;
close all;
hold on;

x = [1 2 4 8 16];

t0 = [ 1.174489 0.736325 1.389596 1.608153 ];
plot(x, t0, 'LineWidth', 3, 'DisplayName', 'models/ironman.obj 3840x2160');

title('hpc-class');
xlabel('Number of Threads');
ylabel('Render Time');
legend('show', 'Location', 'NorthWest');

