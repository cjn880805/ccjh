//yanan1.h

//Sample for room: ����ǵ���ذ�1
//coded by zouwenbin
//data: 2000-11-23

RESIDENT_BEGIN(CRDaliEast_yanan1);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "����ǵ���ذ�1");

	set("resident", "��٤��");

	//add npcs into the room
	add_npc("pub_cunfu");
	
	add_door("�������٤��", "�������٤��", "����ǵ���ذ�1");
	add_door("������س�С·2", "������س�С·2", "����ǵ���ذ�1");

	set("long", "�����Ի�أ�ʵ�����Ǹ��ܴ�ĺ�������ɽ��ˮԴ�ڶ࣬Ҳ�����˴�Ƭ��ũ���ˮ�峺��ˬ�������٤���ĸ�Ů�ڴ�ϴ����ˮ�����Ĳ�������ҵΪ��������������Ȼ����С��ͷ��ʱ�����δ�ͣ����Ҳ������������ˮ���㡣������������������С·���ŵ���ϰ���ȥ��" );
};

RESIDENT_END;
