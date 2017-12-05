function single_4K
clear all;
close all;
hold on;

x = [44115 61152 113955 596682];

t0 = [ 4.571170 2.807682 5.390312 5.926197 ];
plot(x, t0, 'LineWidth', 3, 'DisplayName', '3840x2160');
t0 = [ 1.174489 0.736325 1.389596 1.608153 ];
plot(x, t0, 'LineWidth', 3, 'DisplayName', '1920x1080');

title('hpc-class');
xlabel('Number of Vertices');
ylabel('Render Time');
legend('show', 'Location', 'NorthWest');

