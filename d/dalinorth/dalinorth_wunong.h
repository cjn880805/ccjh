//wunong.h

//Sample for room: �������Ū��
//coded by zouwenbin
//data: 2000-11-24

RESIDENT_BEGIN(CRDaLiNorth_wunong);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "�������Ū��");

	set("resident", "��Ū��");

	//add npcs into the room
	add_npc("pub_wyshangfan");
	
	add_door("����Ǵ���ɽ·", "����Ǵ���ɽ·", "�������Ū��");
	add_door("����Ǵ�ɺӱ�", "����Ǵ�ɺӱ�", "�������Ū��");
	add_door("��������ɴ���", "��������ɴ���", "�������Ū��");

	set("long", "�˴��ѵ�����ı����������ɵ�����θ������������ģ��������ڸ�ɽ�ϡ�����������ɽ֮�������ٲ�����ӿ�Ĵ�ɺӡ���İ����ɽʯ�ݳɣ������࣬����ȫ�ǡ��˳ǲ�������ɽ�Ϸֲ���Щ������ӣ������˸���ţ���������");

};


RESIDENT_END;
