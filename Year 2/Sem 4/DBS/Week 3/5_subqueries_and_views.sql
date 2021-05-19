-- Subqueries in the From Clause

-- #17 
SELECT dept_name, avg_salary FROM (SELECT dept_name, AVG(salary) avg_salary FROM instructor GROUP BY dept_name) WHERE avg_salary > 42000;


-- Views

-- #18 
CREATE VIEW all_courses as SELECT section.course_id, building, room_number FROM section, course WHERE semester = 'Fall' AND year = 2009 AND section.course_id = course.course_id AND dept_name = 'Physics';

-- #19 
SELECT course_id FROM all_courses;

-- #20 
CREATE VIEW department_total_salary as SELECT dept_name, SUM(salary) sum_sal FROM instructor GROUP BY dept_name;
