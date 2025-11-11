DROP TABLE IF EXISTS `course`;

CREATE TABLE
    `course` (
        `id` int (11) NOT NULL AUTO_INCREMENT,
        `teacher_id` INT NOT NULL,
        `name` varchar(255) NOT NULL,
        `time` datetime (3) NOT NULL DEFAULT CURRENT_TIMESTAMP(3),
        `description` varchar(2000),
        `format` varchar(30),
        `structure` varchar(200),
        `duration` varchar(30),
        `price` INT,
        `language` varchar(30),
        `level` varchar(30),
        PRIMARY KEY (`id`)
    ) ENGINE = InnoDB DEFAULT CHARSET = utf8;

INSERT INTO
    `course`
VALUES
    (1, 1, '语文', '2020-01-01 00:00:00.000');

INSERT INTO
    `course`
VALUES
    (2, 1, '数学', '2020-01-01 00:00:00.000');