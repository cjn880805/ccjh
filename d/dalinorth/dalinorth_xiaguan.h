//xiaguan.h

//Sample for room: ������¹س�
//coded by zouwenbin
//data: 2000-11-24

RESIDENT_BEGIN(CRDaLiNorth_xiaguan);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "������¹س�");

	set("resident", "�¹س�");

	//add npcs into the room
	add_npc("pub_tshangfan");/////////////////////////
	add_npc("pub_wyshangfan");

	add_door("����ǲ�ɽ", "����ǲ�ɽ", "������¹س�");
	add_door("����Ƕ�ˮ��", "����Ƕ�ˮ��", "������¹س�");
	add_door("����ǲ�ɽ�в�", "����ǲ�ɽ�в�", "������¹س�");

	set("long", "�¹سǣ�������β�ǣ�Ϊ���޷��������ƴ��Ѽ����١������ӱ���ɽ��´�����ˮ�Ƴ��϶������˵ķ羰�续����ȥ�ϱ߲�Զ���Ǵ���ǣ�������̫�ͳǣ����е�·ͨ���������˸������������ġ�̨��Ϊ����Ҳ���������ġ�");

};

RESIDENT_END;
