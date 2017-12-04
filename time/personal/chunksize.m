function chunksize
clear all;
close all;
hold on;

x = [1 2 4 8 16];

t0 = [ 2.229347 1.274496 0.837284 0.873060 7.448848 ];
plot(x, t0, 'LineWidth', 3, 'DisplayName', '(static, 1)');
t0 = [ 2.259926 1.298466 0.765203 0.784985 7.189409 ];
plot(x, t0, 'LineWidth', 3, 'DisplayName', '(static, 4)');
t0 = [ 2.163130 1.234190 0.776501 0.997283 7.214013 ];
plot(x, t0, 'LineWidth', 3, 'DisplayName', '(static, 8)');
t0 = [ 2.096299 1.191206 0.755017 0.858247 7.106753 ];
plot(x, t0, 'LineWidth', 3, 'DisplayName', '(static, 32)');
t0 = [ 2.086788 1.213297 0.885825 1.547635 7.359226 ];
plot(x, t0, 'LineWidth', 3, 'DisplayName', '(static, 64)');
t0 = [ 2.083969 1.288174 0.943973 1.256815 7.379672 ];
plot(x, t0, 'LineWidth', 3, 'DisplayName', '(static, 128)');
t0 = [ 2.077153 1.262176 0.823633 0.888333 7.151487 ];
plot(x, t0, 'LineWidth', 3, 'DisplayName', '(static)');

title('Personal');
xlabel('Number of Threads');
ylabel('Render Time');
legend('show', 'Location', 'NorthWest');
