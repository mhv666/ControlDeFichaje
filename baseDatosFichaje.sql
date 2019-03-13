--
-- PostgreSQL database dump
--

-- Dumped from database version 10.6
-- Dumped by pg_dump version 10.6

SET statement_timeout = 0;
SET lock_timeout = 0;
SET idle_in_transaction_session_timeout = 0;
SET client_encoding = 'UTF8';
SET standard_conforming_strings = on;
SELECT pg_catalog.set_config('search_path', '', false);
SET check_function_bodies = false;
SET client_min_messages = warning;
SET row_security = off;

--
-- Name: plpgsql; Type: EXTENSION; Schema: -; Owner: 
--

CREATE EXTENSION IF NOT EXISTS plpgsql WITH SCHEMA pg_catalog;


--
-- Name: EXTENSION plpgsql; Type: COMMENT; Schema: -; Owner: 
--

COMMENT ON EXTENSION plpgsql IS 'PL/pgSQL procedural language';


SET default_tablespace = '';

SET default_with_oids = false;

--
-- Name: entrada_salida; Type: TABLE; Schema: public; Owner: usuario
--

CREATE TABLE public.entrada_salida (
    id_entrada_salida integer NOT NULL,
    nombre_entrada_salida character varying NOT NULL
);


ALTER TABLE public.entrada_salida OWNER TO usuario;

--
-- Name: entrada_salida_id_entrada_salida_seq; Type: SEQUENCE; Schema: public; Owner: usuario
--

CREATE SEQUENCE public.entrada_salida_id_entrada_salida_seq
    AS integer
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1;


ALTER TABLE public.entrada_salida_id_entrada_salida_seq OWNER TO usuario;

--
-- Name: entrada_salida_id_entrada_salida_seq; Type: SEQUENCE OWNED BY; Schema: public; Owner: usuario
--

ALTER SEQUENCE public.entrada_salida_id_entrada_salida_seq OWNED BY public.entrada_salida.id_entrada_salida;


--
-- Name: estado; Type: TABLE; Schema: public; Owner: usuario
--

CREATE TABLE public.estado (
    id_estado integer NOT NULL,
    nombre_estado character varying NOT NULL
);


ALTER TABLE public.estado OWNER TO usuario;

--
-- Name: estado_id_estado_seq; Type: SEQUENCE; Schema: public; Owner: usuario
--

CREATE SEQUENCE public.estado_id_estado_seq
    AS integer
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1;


ALTER TABLE public.estado_id_estado_seq OWNER TO usuario;

--
-- Name: estado_id_estado_seq; Type: SEQUENCE OWNED BY; Schema: public; Owner: usuario
--

ALTER SEQUENCE public.estado_id_estado_seq OWNED BY public.estado.id_estado;


--
-- Name: trabajador; Type: TABLE; Schema: public; Owner: usuario
--

CREATE TABLE public.trabajador (
    id_trabajador integer NOT NULL,
    nombre_trabajador character varying NOT NULL,
    ean13_trabajador numeric NOT NULL,
    pass character varying NOT NULL,
    id_estado integer NOT NULL
);


ALTER TABLE public.trabajador OWNER TO usuario;

--
-- Name: trabajador_id_trabajador_seq; Type: SEQUENCE; Schema: public; Owner: usuario
--

CREATE SEQUENCE public.trabajador_id_trabajador_seq
    AS integer
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1;


ALTER TABLE public.trabajador_id_trabajador_seq OWNER TO usuario;

--
-- Name: trabajador_id_trabajador_seq; Type: SEQUENCE OWNED BY; Schema: public; Owner: usuario
--

ALTER SEQUENCE public.trabajador_id_trabajador_seq OWNED BY public.trabajador.id_trabajador;


--
-- Name: trabajador_in_out; Type: TABLE; Schema: public; Owner: usuario
--

CREATE TABLE public.trabajador_in_out (
    id_trabajador_in_out integer NOT NULL,
    id_entrada_salida integer NOT NULL,
    id_trabajador integer NOT NULL,
    "timestamp" timestamp without time zone NOT NULL
);


ALTER TABLE public.trabajador_in_out OWNER TO usuario;

--
-- Name: trabajador_in_out_id_trabajador_in_out_seq; Type: SEQUENCE; Schema: public; Owner: usuario
--

CREATE SEQUENCE public.trabajador_in_out_id_trabajador_in_out_seq
    AS integer
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1;


ALTER TABLE public.trabajador_in_out_id_trabajador_in_out_seq OWNER TO usuario;

--
-- Name: trabajador_in_out_id_trabajador_in_out_seq; Type: SEQUENCE OWNED BY; Schema: public; Owner: usuario
--

ALTER SEQUENCE public.trabajador_in_out_id_trabajador_in_out_seq OWNED BY public.trabajador_in_out.id_trabajador_in_out;


--
-- Name: entrada_salida id_entrada_salida; Type: DEFAULT; Schema: public; Owner: usuario
--

ALTER TABLE ONLY public.entrada_salida ALTER COLUMN id_entrada_salida SET DEFAULT nextval('public.entrada_salida_id_entrada_salida_seq'::regclass);


--
-- Name: estado id_estado; Type: DEFAULT; Schema: public; Owner: usuario
--

ALTER TABLE ONLY public.estado ALTER COLUMN id_estado SET DEFAULT nextval('public.estado_id_estado_seq'::regclass);


--
-- Name: trabajador id_trabajador; Type: DEFAULT; Schema: public; Owner: usuario
--

ALTER TABLE ONLY public.trabajador ALTER COLUMN id_trabajador SET DEFAULT nextval('public.trabajador_id_trabajador_seq'::regclass);


--
-- Name: trabajador_in_out id_trabajador_in_out; Type: DEFAULT; Schema: public; Owner: usuario
--

ALTER TABLE ONLY public.trabajador_in_out ALTER COLUMN id_trabajador_in_out SET DEFAULT nextval('public.trabajador_in_out_id_trabajador_in_out_seq'::regclass);


--
-- Data for Name: entrada_salida; Type: TABLE DATA; Schema: public; Owner: usuario
--

INSERT INTO public.entrada_salida VALUES (1, 'Entrada');
INSERT INTO public.entrada_salida VALUES (2, 'Salida');


--
-- Data for Name: estado; Type: TABLE DATA; Schema: public; Owner: usuario
--

INSERT INTO public.estado VALUES (1, 'Activo');
INSERT INTO public.estado VALUES (2, 'Inactivo');


--
-- Data for Name: trabajador; Type: TABLE DATA; Schema: public; Owner: usuario
--

INSERT INTO public.trabajador VALUES (2, 'Marti', 9780201379624, '1234', 1);


--
-- Data for Name: trabajador_in_out; Type: TABLE DATA; Schema: public; Owner: usuario
--

INSERT INTO public.trabajador_in_out VALUES (18, 1, 2, '2019-03-12 17:36:33.496608');
INSERT INTO public.trabajador_in_out VALUES (23, 2, 2, '2019-03-12 18:46:35.015754');
INSERT INTO public.trabajador_in_out VALUES (24, 1, 2, '2019-03-12 18:50:37.626242');


--
-- Name: entrada_salida_id_entrada_salida_seq; Type: SEQUENCE SET; Schema: public; Owner: usuario
--

SELECT pg_catalog.setval('public.entrada_salida_id_entrada_salida_seq', 2, true);


--
-- Name: estado_id_estado_seq; Type: SEQUENCE SET; Schema: public; Owner: usuario
--

SELECT pg_catalog.setval('public.estado_id_estado_seq', 2, true);


--
-- Name: trabajador_id_trabajador_seq; Type: SEQUENCE SET; Schema: public; Owner: usuario
--

SELECT pg_catalog.setval('public.trabajador_id_trabajador_seq', 2, true);


--
-- Name: trabajador_in_out_id_trabajador_in_out_seq; Type: SEQUENCE SET; Schema: public; Owner: usuario
--

SELECT pg_catalog.setval('public.trabajador_in_out_id_trabajador_in_out_seq', 24, true);


--
-- Name: entrada_salida entrada_salida_pkey; Type: CONSTRAINT; Schema: public; Owner: usuario
--

ALTER TABLE ONLY public.entrada_salida
    ADD CONSTRAINT entrada_salida_pkey PRIMARY KEY (id_entrada_salida);


--
-- Name: estado estado_nombre_estado_key; Type: CONSTRAINT; Schema: public; Owner: usuario
--

ALTER TABLE ONLY public.estado
    ADD CONSTRAINT estado_nombre_estado_key UNIQUE (nombre_estado);


--
-- Name: estado estado_pkey; Type: CONSTRAINT; Schema: public; Owner: usuario
--

ALTER TABLE ONLY public.estado
    ADD CONSTRAINT estado_pkey PRIMARY KEY (id_estado);


--
-- Name: trabajador trabajador_ean13_trabajador_key; Type: CONSTRAINT; Schema: public; Owner: usuario
--

ALTER TABLE ONLY public.trabajador
    ADD CONSTRAINT trabajador_ean13_trabajador_key UNIQUE (ean13_trabajador);


--
-- Name: trabajador_in_out trabajador_in_out_pkey; Type: CONSTRAINT; Schema: public; Owner: usuario
--

ALTER TABLE ONLY public.trabajador_in_out
    ADD CONSTRAINT trabajador_in_out_pkey PRIMARY KEY (id_trabajador_in_out);


--
-- Name: trabajador trabajador_pkey; Type: CONSTRAINT; Schema: public; Owner: usuario
--

ALTER TABLE ONLY public.trabajador
    ADD CONSTRAINT trabajador_pkey PRIMARY KEY (id_trabajador);


--
-- Name: trabajador FK_id_estado; Type: FK CONSTRAINT; Schema: public; Owner: usuario
--

ALTER TABLE ONLY public.trabajador
    ADD CONSTRAINT "FK_id_estado" FOREIGN KEY (id_estado) REFERENCES public.estado(id_estado) ON UPDATE CASCADE ON DELETE CASCADE;


--
-- Name: trabajador_in_out FK_trabajador; Type: FK CONSTRAINT; Schema: public; Owner: usuario
--

ALTER TABLE ONLY public.trabajador_in_out
    ADD CONSTRAINT "FK_trabajador" FOREIGN KEY (id_trabajador) REFERENCES public.trabajador(id_trabajador) ON UPDATE CASCADE ON DELETE CASCADE;


--
-- Name: trabajador_in_out trabajador_in_out_id_entrada_salida_fkey; Type: FK CONSTRAINT; Schema: public; Owner: usuario
--

ALTER TABLE ONLY public.trabajador_in_out
    ADD CONSTRAINT trabajador_in_out_id_entrada_salida_fkey FOREIGN KEY (id_entrada_salida) REFERENCES public.entrada_salida(id_entrada_salida) ON UPDATE CASCADE ON DELETE CASCADE;


--
-- PostgreSQL database dump complete
--

