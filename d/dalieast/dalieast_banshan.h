//banshan.h

//Sample for room: ����ǰ�ɽ����
//coded by zouwenbin
//data: 2000-11-23

RESIDENT_BEGIN(CRDaliEast_banshan);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "����ǰ�ɽ����");

	set("resident", "���۲�");

	//add npcs into the room
	add_npc("pub_kanzhuren");
	
	add_door("���������ɽ��", "���������ɽ��", "����ǰ�ɽ����");
	add_door("����ǲ��۲�", "����ǲ��۲�", "����ǰ�ɽ����");

	set("long", "һ��Ƭï�ܵĳ������������ڰ�ɽ���Ļ����ϡ����ӶԴ��������������˵�ǣ�������Ҫ�Ľ������ϣ�Ҳ���ճ�������Ʒ��ԭ���ϡ�ɽ�µĴ�ׯ��İ����˾�����ɽ���ɷ����ӡ�����ɽ����Ϫ���£�������ˮ���Ѿ��Ĵ�ɽ�񾭳��ѿ����µ����Ӷ���Ϫ�У�����˳ˮƮ���������Ӹ�����Ϫˮ������������" );
};


RESIDENT_END;
