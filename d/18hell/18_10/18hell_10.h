//18hell_10.h
//ʮ�˵���������𺣵���BOSS����

//coded by sound
//data: 2001-10-21

ROOM_BEGIN(CR18hell_10);

virtual void create()			//Call it when Room Create
{
	set_name("������");
	
	add_npc("shuizhizi");
	add_npc("diyu_shizhe10");

};

virtual int do_look(CChar * me)
{
	say("����״�Ļ�����ȼ�գ����̹�����һ���޼ʣ�����������յĲ�ʬ��Լ�ɼ����м���һ�޴�����±��ϣ������Ѻ��������ǰ���ұߣ��е������߹��š����ţ��еı�������������������һ�޹�����߾�һ������ŭ���Ž�������𺣡�", me);
	say("������ʯ���ϣ����������˫�ֵġ����ֻ𳵣������������ߣ���������𺣡�", me);
	SendMenu(me);
	return 1;
}

ROOM_END;
