SELECT
    e.machine_id,
    ROUND(((e.total_end - s.total_start)/tot),3) AS processing_time
FROM (
    SELECT machine_id, SUM(timestamp) AS total_end,count(timestamp) as tot
    FROM Activity
    WHERE activity_type = 'end'
    GROUP BY machine_id
) e
JOIN (
    SELECT machine_id, SUM(timestamp) AS total_start,timestamp
    FROM Activity
    WHERE activity_type = 'start'
    GROUP BY machine_id
) s
ON e.machine_id = s.machine_id;