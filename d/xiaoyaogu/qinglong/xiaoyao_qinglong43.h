//xiaoyao_qinglong43.h �������Ĳ�
//�ز� 2002��12��17

XiaoYao_BEGIN(CRXiaoYao_qinglong43);

virtual void create()
{
	set_name( "�������Ĳ�");
	
	add_door("�������Ĳ�2", "��ң���������Ĳ�42", "��ң���������Ĳ�43");
	
	add_door("�������Ĳ�4", "��ң���������Ĳ�44", "��ң���������Ĳ�43");
	
	add_npc("xy_qinglong4");
	add_npc("xy_qinglong4");

	set("����",random(3)+5);
	set("λ��",random(2)+1);
	set("����","����");
};

int valid_leave(CChar * me, const char * dir)
{
	if(userp(me))
	{
		if(!me->query("xy/renwu4_3"))
		{
			me->move(load_room("��ɽ������"));
			return 0;
		}
		else if(!me->query_temp("xy/renwu4_1"))
		{
			tell_object(me, "\n$HIRͨ������һƬ�����滹��ʱ����һЩ�����������ֻ�ŵ����ľ������������ٽ�ǰһ�����������ǵ���ʦ������ʦ�������Ϊ��׳׳����\n");
			me->move(load_room("��ң�ȿյ�"));
			return 0;
		}
		CContainer * ShouWei=present("ping peng");
		if(ShouWei)
		{
			tell_object(me, "$HIR����������ȵ������󵨿�ͽ�������Ҵ����䱦������������������£���");
			return 0;
		}
	}
	return CRoom::valid_leave(me, dir);
}
XiaoYao_END;
