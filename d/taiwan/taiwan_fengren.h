//taiwan_fengren.h
//Sample for room: ̨�����Ժ

//coded by Teapot

//data: 2000-11-4



ROOM_BEGIN(CRTaiWan_fengren);



virtual void create()			//Call it when Room Create
{
	set_name( "̨�����Ժ");

	set("monster_chance", 20);

	add_door("̨������Ժ", "̨������Ժ", "̨�����Ժ");
	add_door("̨������Ժ", "̨������Ժ", "̨�����Ժ");
	add_door("̨����ͨ��", "̨����ͨ��", "̨�����Ժ");

	add_door("̨��򹷸�", "̨��򹷸�", "̨�����Ժ");

	set("long", "�򹷸�λ��̨���ϲ��������С�������е����������ھ�����Ͽ�壬��ǫ̈̄��һ���ۡ�  " );
};

ROOM_END;