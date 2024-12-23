//LingJiu_mishi.h
//Sample for room: ������翷��ɽ�ܵ�3


ROOM_BEGIN(CRLingJiu_mishi);

virtual void create()			//Call it when Room Create
{
	set_name( "���պ�ɽʯ��");

	add_door("���պ�ɽ�ܵ�3", "���պ�ɽ�ܵ�3", "���պ�ɽʯ��");
	set("no_fight",1);
	set("long","" );

};

virtual int do_look(CChar * me)
{
	time_t t;	
	time(&t);
	char msg[255];
	int i,j,level,num;
	if(me->query("lj/endtime") && t < me->query("lj/endtime")||wizardp(me))
	{
		say("��۲�ʯ��,����ֻ���ı���ʯ��ĥ�����ǹ⻬��ʯ���Ͽ������������������ԲȦ��ÿ��Ȧ�ж����˸��ָ�����ͼ�Ρ�", me);
		say("�е��������е������Σ��е��ǲ�ȱ��ȫ�����֣�����Щֻ�ǼǺź�������", me);
		say("ԲȦ��ע�š���һ�������׶���������һ�������Ӷ��������֣�ԲȦ֮��������ǧ������Ҳ�а˾Űٸ���һʱȴ���￴����ȫ��", me);
		static char wuxue[5][20]=
		{
			"dodge","strike","hand","finger","sword"
		};
		static char wuxue1[5][20]=
		{
			"��������","�����Ʒ�","�����ַ�","����ָ��","��������"
		};
		if(!me->query_temp("lj/skill/num"))
		{
			int count=1+int(me->query("int")/10);
			if(count>4)
				count=4;
			me->set_temp("lj/skill/num",count);
			for(i=0;i<me->query_temp("lj/skill/num");i++)
			{
				level=random(110)+360;
				num=random(5);
				if(i)
				{
					for(j=0;j<i;j++)
					{
						if(num==me->query_temp(snprintf(msg, 255,"lj/skill/skill_num%d",j)))
						{
							num=random(5);
							j=-1;
						}
					}
				}
				if(level>me->query_skill(wuxue1[num],1) && level<450)
				{
					level=level+random(20);//ȷ����������ļ��ܸ�����ҵļ���
				}
				me->set_temp(snprintf(msg, 255,"lj/skill/skill_num%d",i),num);
				me->set_temp(snprintf(msg, 255,"lj/skill/skill_name%d",i),wuxue1[num]);
				me->set_temp(snprintf(msg, 255,"lj/skill/skill_level%d",i),level);
				me->set_temp(snprintf(msg, 255,"lj/skill/%d",num),level);
				AddMenuItem(snprintf(msg, 255,"%s   %d",wuxue1[num],level), snprintf(msg, 255,"$0ji_%s $1",wuxue[num]), me);
			}
		}
		else
		{
			for(i=0;i<me->query_temp("lj/skill/num");i++)
			{
				AddMenuItem(snprintf(msg, 255,"%s   %d",me->querystr_temp(snprintf(msg, 255,"lj/skill/skill_name%d",i)),me->query_temp(snprintf(msg, 255,"lj/skill/skill_level%d",i))), snprintf(msg, 255,"$0ji_%s $1",wuxue[me->query_temp(snprintf(msg, 255,"lj/skill/skill_num%d",i))]), me);
			}
		}
		SendMenu(me);
	}
	else
	{
		tell_object(me, "\n$HIR���ƺ��Ѿ����ܴ�ʯ�����������ʲô��ֻ����ͷ�����ͣ�ҡҡ��׹��������֧����ȥ��");
		tell_object(me, "$HIR���������У������ʯ�ڣ������߳�ʯ�ҡ�");
		me->del("lj/endtime");
		if(me->querymap_temp("lj"))
			me->delete_temp("lj");
		me->move(load_room("���ջ�԰"));
	}
	return 1;
}


int handle_action(char *comm, CChar *me, char * arg, char * target)
{
	time_t t;
	time(&t);
	if(me->query("lj/endtime") && t < me->query("lj/endtime")||wizardp(me))
	{
/*		if(strcmp(comm, "ji_force") == 0 )
		{
			tell_object(me, "$HIR\n�㶨����ʯ�ڵĶ�������ȥ��ֻ�����Ͽ������˵��澭������\n");
			tell_object(me, "���̲�ס�����˹���������");
			
			me->set_temp("block_msg/all",1);
			int rnd = 100 - me->query_int();
			if(rnd<30)
				rnd=30;
			me->disable_player("������");
			me->set_temp("lj/skill_name","force");
			me->set_temp("lj/skill_id","�����ڹ�");
			me->set_temp("lj/skill_index",1);
			me->set_temp("lj/skill_level",me->query_temp("lj/skill/0"));
			me->call_out(wakeup, rnd);
			
			return 1;
		}
*/		if(strcmp(comm, "ji_dodge") == 0 )
		{
			tell_object(me, "$HIR\n�㶨����ʯ�ڵ���������ȥ��ֻ����������ͼ�Σ��ƺ���ƥ����");
			tell_object(me, "$HIR���ױ��У�������������������������շ���һ�㡣");
			tell_object(me, "$HIR��ϸ�������µ�������ֻ��һ���������ƺ��ڲ�����ǰ��ӿ��ֱ�������Ʊڷɳ���\n");
			tell_object(me, "�㿴��Ƭ�̣���Ϣ��ӿ������");
			
			me->set_temp("block_msg/all",1);
			int rnd = 100 - me->query_int();
			if(rnd<30)
				rnd=30;
			me->disable_player("������");
			me->set_temp("lj/skill_name","dodge");
			me->set_temp("lj/skill_id","��������");
			me->set_temp("lj/skill_index",2);
			me->set_temp("lj/skill_level",me->query_temp("lj/skill/0"));
			me->call_out(wakeup, rnd);
			
			return 1;
		}
		else if(strcmp(comm, "ji_strike") == 0 )
		{
			tell_object(me, "$HIR\n�㶨����ʯ�ڵ����ϴ���ȥ��ֻ�����ϻ��������ڶ��ơ�");
			tell_object(me, "$HIR����������Ʒ�ƽƽ���棬����������ʽ���ᣬ�ս�������߰˷���");
			tell_object(me, "$HIR�ƻ���ǧ���ݺύ���仯Ī�⡣\n");
			tell_object(me, "�㿴�����������֪��������ϥ���£��Ա�ڤ˼����������");
			
			me->set_temp("block_msg/all",1);
			int rnd = 100 - me->query_int();
			if(rnd<30)
				rnd=30;
			me->disable_player("������");
			me->set_temp("lj/skill_name","strike");
			me->set_temp("lj/skill_id","�����Ʒ�");
			me->set_temp("lj/skill_index",3);
			me->set_temp("lj/skill_level",me->query_temp("lj/skill/1"));
			me->call_out(wakeup, rnd);
			
			return 1;
		}
		else if(strcmp(comm, "ji_hand") == 0 )
		{
			tell_object(me, "$HIR\n�㶨����ʯ�ڵ��Ϸ�����ȥ��ֻ�����ϻ����˲�ͬ��״���֡�\n");
			tell_object(me, "��ڤ˼���죬˫�ָ��ű�����Щ���Ƶķ���Ȼ��������ֻ���������޳�������");
			
			me->set_temp("block_msg/all",1);
			int rnd = 100 - me->query_int();
			if(rnd<30)
				rnd=30;
			me->disable_player("������");
			me->set_temp("lj/skill_name","hand");
			me->set_temp("lj/skill_id","�����ַ�");
			me->set_temp("lj/skill_index",4);
			me->set_temp("lj/skill_level",me->query_temp("lj/skill/2"));
			me->call_out(wakeup, rnd);
			
			return 1;
		}
		else if(strcmp(comm, "ji_finger") == 0 )
		{
			tell_object(me, "$HIR\n�㶨����ʯ�ڵ���������ȥ��ֻ�����Ϻ�һ����ݽ����");
			tell_object(me, "$HIR�������ɷ��裬���������֮�侹��һ·ָ����\n");
			tell_object(me, "�㿴���������ָ��������˳�Ź���һ·���𡣡���");
			
			me->set_temp("block_msg/all",1);
			int rnd = 100 - me->query_int();
			if(rnd<30)
				rnd=30;
			me->disable_player("������");
			me->set_temp("lj/skill_name","finger");
			me->set_temp("lj/skill_id","����ָ��");
			me->set_temp("lj/skill_index",5);
			me->set_temp("lj/skill_level",me->query_temp("lj/skill/3"));
			me->call_out(wakeup, rnd);
			
			return 1;
		}
		else if(strcmp(comm, "ji_sword") == 0 )
		{
			tell_object(me, "$HIR\n�㶨����ʯ�ڵĶ��ϴ���ȥ��ֻ��������������Ŀ������֡�");
			tell_object(me, "$HIR����ǧ������֮�У���Щ�ʻ���Ȼ����һ�ѳ��������ж���ʮ�ѡ�");
			tell_object(me, "$HIR��˽��λ���ֱ����Ʋ���࣬�еĽ��⳯�ϣ��е����£��е�б�����ɣ��еĺ�����׹��\n");
			tell_object(me, "�㿴�ó��ˣ���֪����������ʯ�ڵ�ͼ�ıȻ�������������");
			
			me->set_temp("block_msg/all",1);
			int rnd = 100 - me->query_int();
			if(rnd<30)
				rnd=30;
			me->disable_player("������");
			me->set_temp("lj/skill_name","sword");
			me->set_temp("lj/skill_id","��������");
			me->set_temp("lj/skill_index",6);
			me->set_temp("lj/skill_level",me->query_temp("lj/skill/4"));
			me->call_out(wakeup, rnd);
			
			return 1;
		}
	}
	else
	{
		tell_object(me, "\n$HIR���ƺ��Ѿ����ܴ�ʯ�����������ʲô��ֻ����ͷ�����ͣ�ҡҡ��׹��������֧����ȥ��");
		tell_object(me, "$HIR���������У������ʯ�ڣ������߳�ʯ�ҡ���");
		me->del("lj/endtime");
		if(me->querymap_temp("lj"))
			me->delete_temp("lj");
		if(!me->query("lj/renwu10"))
			me->del("lj");
		me->move(load_room("���ջ�԰"));
	}
	return CRoom::handle_action(comm, me, arg, target);
}

static void wakeup(CContainer * ob, LONG param1, LONG param2)
{
	CChar * me = (CChar *)ob;
	char msg[255];
	if(!me) return;

	me->delete_temp("block_msg/all");
	me->enable_player();

	while( (me->environment())->is_character() )
		me->move((me->environment())->environment());
	
	
	LONG need_points =  me->skill_need_points(me->querystr_temp("lj/skill_name"));
	LONG need_exp = 3*(need_points / me->learn_bonus() + 1);
	
	if(me->query_valid_exp() < need_exp)
	{
		tell_object(me, "\n$HIR��Ȼ�䣬����û�������Խ��Խʢ���ӵ����в���ӿ������������������������ͻ��Ծ���ѹ�֮����");
		tell_object(me, snprintf(msg, 255, "$HIR�����׵����Լ��Ľ��������������޷���ȥ����ʯ���ϸ�����书�����ɵ�̾�˿�����ѧϰ%s����%ld�㾭�飩��\n", me->querystr_temp("lj/skill_id"), need_exp));
	}
	else if(me->query_skill(me->querystr_temp("lj/skill_name"),1)>=me->query_temp("lj/skill_level"))
	{
		tell_object(me, "\n$HIR��Ȼ�䣬��ֻ����һ��ͷ�����ͣ��޷���������ȥ����������ʯ���ϵ����Ÿ����书��");
		tell_object(me, "$HIR�����׵����Լ����书���н����Ѿ���ʱ�޷�ͻ�������ˣ����ɵ�̾�˿�����");
	}
	else
	{
		me->set_skill(me->querystr_temp("lj/skill_name"),me->query_skill(me->querystr_temp("lj/skill_name"),1)+1);
		switch(me->query_temp("lj/skill_index"))
		{
/*		case 1:
			tell_object(me,"$HIR\n����ڤ���У���Ȼ���þ�������������Ϣ�ܶ����������򾹺���ʯ�������̻���ͼ��һ�¡�");
			tell_object(me,"$HIR��̼��ֹ��ɻص��ԭ������������ڲ�֪��������ǿ�ˡ�");
			break;
*/		case 2:
			tell_object(me,"$HIR\n����ڤ���У���Ȼ������ϥ���������������о�������֮�С�");
			tell_object(me,"$HIRһ�������F����������Ÿ��У�ѭ�������У����أ���һ�������ҽŸ��У�ѭ�������У����ʺ����������");
			break;
		case 3:
			tell_object(me,"$HIR\n����ڤ���У���Ȼ����̯��˫ϥ�ϵ������У��������İ�������Ȫ������ۧ�š���ʹ���ڹء����ꡢ�͹����г��Ѩλ......");
			tell_object(me,"$HIR�������ľ����ļ�Ȫ�����顢�ٺ��������ͨ���ۧ�����š��ٸ����ٳ���Ѩλ......");
			tell_object(me,"$HIR����Щ�����ʹ������һʱ��������ʹ������û��������ָо�����ʧ�ˡ�");
			break;
		case 4:
			tell_object(me,"$HIR\n��һ·������ȥ������ʯ�ұ�����ַ������֡�");
			break;
		case 5:
			tell_object(me,"$HIR\nͻȻ����������͵�һ�����������������ָ��ֱ͸ǽ���롣");
			break;
		case 6:
			tell_object(me,"$HIR\n����ڤ���У�����ͻ�ž�â�����������аγ�����������������ʱ���ڽ������磬յ��֮�󷽲��ս���");
			break;
		}
		tell_object(me, snprintf(msg, 255,"$HIR\n��ƾ����ḻ�Ľ�������(-%d)����%s������������һ�㡣\n",need_exp,me->querystr_temp("lj/skill_id")));
		me->add("combat_exp",-need_exp);
	}
	me->delete_temp("lj/skill_name");
	me->delete_temp("lj/skill_id");
	me->delete_temp("lj/skill_index");
	me->delete_temp("lj/skill_level");
	me->FlushMySkill(me);
	me->UpdateMe();
}


ROOM_END;
