//junying77.h  �о�˧��
//�ز� 2003��6��5

ROOM_BEGIN(CRGuanWai_junying77);

virtual void create()			
{
	set_name("�о�˧��");

	set("renwu", 1);
	set("boss", 1);

	add_npc("bj_ma");
	add_npc("bj_wangqiuren");

	add_door("�о�Ӫ��1", "�����о�Ӫ��1", "�����о�˧��");
	add_door("�о�Ӫ��2", "�����о�Ӫ��2", "�����о�˧��");
	add_door("�о�Ӫ��3", "�����о�Ӫ��3", "�����о�˧��");
	add_door("�о�Ӫ��4", "�����о�Ӫ��4", "�����о�˧��");
	add_door("�о�Ӫ��5", "�����о�Ӫ��5", "�����о�˧��");
	add_door("�о�Ӫ��6", "�����о�Ӫ��6", "�����о�˧��");

	set("long","������Ӫ�ǰ������������������������أ�����ƫӪ��ס�����կ������λ���о�֮���ģ��β����ơ����ó�������Ҳ�Ǿö����飬��սɳ�����罫��" );

};

int handle_action(char *comm, CChar *me, char * arg, char * target)
{
	if(!me->query_temp("zhang/����ǿ_jion"))
	{
		me->move(load_room("��ɽ������"));
		return 1;
	}
	else 
	{
		CContainer * obj = Present(atol(target));
		if(EQUALSTR(obj->querystr("name"),"������"))
		{
			if(!strcmp(comm, "kill")||!strcmp(comm, "fight")||!strcmp(comm, "cast"))
			{
				CContainer * ma=present("ma");
				if(ma||!query("ok"))
				{
					tell_object(me, "�������һ����Ҫ�붯�֣��ȹ�����һ�أ�");
					return 1;
				}
			}
		}
	}
	return CRoom::handle_action(comm, me, arg, target);
}


ROOM_END;
