//feilihu.h

//Sample for room: ��������
//coded by zouwenbin
//data: 2000-11-23

RESIDENT_BEGIN(CRDaLisouth_feilihu);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "��������");

	set("resident", "ϲ��");

	add_npc("pub_playboy");
	add_npc("pub_cunfu");   //add by zdn 2001-07-13

	add_door("�����ϲ�ݳ�", "�����ϲ�ݳ�", "�������������");
	add_door("�����³����", "�����³����", "�������������");
	add_door("�������������", "�������������", "�������������");

	set("long", "��վ���������ı��������߲�Զ����ϲ�ݳǡ��˺����󣬵���ˮ�峺�������У�����̨�Ĵ��������ں��ϲ��㡣��֮�ϺͶ��߰�ɽ�϶���̨�Ĵ����е�·�ƺ�������ͨ���ϱߡ�" );
};


RESIDENT_END;
