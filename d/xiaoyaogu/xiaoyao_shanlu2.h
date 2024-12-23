//xiaoyao_shanlu2.h ɽ·1
//�ز� 2002��12��5

XiaoYao_BEGIN(CRXiaoYao_shanlu2);

virtual void create()
{
	set_name( "ɽ·2");

	set("monster_chance",60);
	set("no_autosave",1);

	add_door("��ң��������嶥", "��ң��������嶥", "��ң��������ɽ·2");
	add_door("��ң��������ɽ��", "��ң��������ɽ��", "��ң��������ɽ·2");

};


int valid_leave(CChar * me, const char * dir)
{
	if(EQUALSTR(dir,"��ң��������嶥"))
	{
		if(me->query("xy/renwu3_2") && !me->query("xy/renwu3_3"))
		{
			//��ңŮ����ֻ������������嶥ս��
			CNpc * XyNpc ;
			CFightRoom * obj =  (CFightRoom *)load_item("fight_room");	
			obj->set_name("��ңŮ��ս��", "fight_room");
			obj->move(load_room("��ң��������嶥"));
			
			for(int i=0;i<4;i++)
			{
				CChar * DuWu = load_npc("animal_bear");
				DuWu->move(obj);
				DuWu->set("owner",me->id(1));
				obj->Join_Team(DuWu, CFightRoom::FIGHT_TEAM_A);
			}
			XyNpc= load_npc("xy_xiaoyaonv");
			XyNpc->move(obj);
			obj->Join_Team(XyNpc, CFightRoom::FIGHT_TEAM_B);
			obj->Begin_Fight(0);

			me->set_temp("xy/renwu3_1",1);//������ңŮ�����ֻ����
		}
	}
	return CRoom::valid_leave(me, dir);
}
XiaoYao_END;
