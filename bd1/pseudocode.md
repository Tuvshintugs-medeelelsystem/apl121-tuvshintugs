START

SET max_month = 1
SET max_usage_month = 1
SET total_cost = 0
SET max_cost = 0
SET max_kwh = -1

OUTPUT "=== ЦАХИЛГААНЫ ТӨЛБӨРИЙН ТООЦОО ==="
OUTPUT "Сар, Хэрэглээ (kWh), Төлбөр (MNT)"

FOR month = 1 TO 12

    DO
        OUTPUT "Сарын цахилгааны хэрэглээг оруулна уу (kWh)"
        INPUT kwh

        IF input is not numeric THEN
            OUTPUT "Алдаа! Тоон утга оруулна уу."
            CLEAR invalid input
            SET kwh = -1
        END IF

        IF kwh < 0 OR kwh > 1000000 THEN
            OUTPUT "Хүчингүй оролт! 0-1000000 хооронд утга оруулна уу."
        END IF

    WHILE kwh < 0 OR kwh > 1000000

    IF kwh <= 150 THEN
        SET cost = kwh * 120

    ELSE IF kwh <= 300 THEN
        SET cost = 150 * 120 + (kwh - 150) * 180

    ELSE
        SET cost = 150 * 120 + 150 * 180
                   + (kwh - 300) * 250
    END IF

    OUTPUT month, kwh, cost

    SET total_cost = total_cost + cost

    IF cost > max_cost THEN
        SET max_cost = cost
        SET max_month = month
    END IF

    IF kwh > max_kwh THEN
        SET max_kwh = kwh
        SET max_usage_month = month
    END IF

END FOR

OUTPUT "Жилийн нийт төлбөр:", total_cost
OUTPUT "Хамгийн өндөр төлбөртэй сар:", max_month, max_cost
OUTPUT "Хамгийн их хэрэглээтэй сар:", max_usage_month, max_kwh

OUTPUT "=== ЦАХИЛГААН ХЭМНЭХ ЗӨВЛӨМЖ ==="
OUTPUT "1. Ашиглаагүй гэрлээ унтраах."
OUTPUT "2. LED гэрэл ашиглах."
OUTPUT "3. Хэрэглээгүй төхөөрөмжөө залгуураас салгах."
OUTPUT "4. Сарын хэрэглээгээ тогтмол хянах."

END