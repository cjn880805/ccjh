//yanan2.h

//Sample for room: ������س�С·2
//coded by zouwenbin
//data: 2000-11-23

RESIDENT_BEGIN(CRDaliEast_yanan2);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "������س�С·2");

	set("resident", "�̼�ɽ");

	add_npc("pub_bing");   //add zdn 2001-07-12

	add_door("����Ǳ̼�ɽ��", "����Ǳ̼�ɽ��", "������س�С·2");
	add_door("����ǵ���ذ�1", "����ǵ���ذ�1", "������س�С·2");

	set("long", "����һ�����ŵ���ϰ���С·������а������Ϯ�ˡ�Զ����غ��棬�̲�����������Ϸˮ��ңң�ɼ��δ����洬�ᷫ���ơ��˵����˼��ɾ�����·����ֱ�ϵ��������Ⱥɽ��" );
};


RESIDENT_END;
