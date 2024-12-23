//xy_liqiouheng.h ����ۣ���ң��СԺ����NPC��
//�ز� 2002��12��12

NPC_BEGIN(CNxy_liqiouheng1);

virtual void create()
{    
    set_name("�����", "li qiou heng");
    set("long","������һϮ���Ƴ�����������֬��üĿ�续��������̬�򷽣���Ц֮�䣬һ�ɽ���̬֮��Ȼ������");	
    set("gender", "Ů��"); 
    set("age", 20);

    set("str", 20); 
    set("int", 20);
    set("con", 28);
    set("dex", 30);
    set("per", 40);

    set("icon",6);
	set("title","��ң��");
	create_family("��ң��", 1, "����");

    set("max_hp", 18000);
    set("mp", 9000);
    set("max_mp", 9000);
    set("mp_factor", 120); 
    set("combat_exp", 5000000); 

	set("chat_chance", 30);
	
	set("no_kill",1);

    set_skill("force", 300);
    set_skill("xiaowuxiang", 300);
    set_skill("dodge", 300);
    set_skill("xiaoyao_bu", 300);
    set_skill("unarmed", 300);
    set_skill("liuyang_zhang", 300);
    set_skill("parry", 300);
    set_skill("blade", 300);
    set_skill("xiaoyao_dao", 300);
    set_skill("zhemei_shou", 300);
    set_skill("hand", 300);
	set_skill("literate", 280);
    
    map_skill("force", "xiaowuxiang");
    map_skill("dodge", "xiaoyao_bu");
    map_skill("hand", "zhemei_shou");
    map_skill("unarmed", "liuyang_zhang");
    map_skill("parry", "xiaoyao_dao");
    map_skill("blade", "xiaoyao_dao");
    
    prepare_skill("hand","zhemei_shou");
    prepare_skill("unarmed","liuyang_zhang");
    set("apply/armor", 200);
    set("apply/damage", 150);
    carry_object("gangdao")->wield();

	call_out(do_die, 900);	
}

int do_talk(CChar * me, char * ask = NULL)
{
	if((EQUALSTR((me->environment())->querystr("base_name"), "��ң��СԺ" )))
	{
		if(me->query("xy/renwu7_2") && me->query_temp("xy/renwu7_3") && me->query("xy/renwu7_3")<1)
		{
			if(! strlen(ask))
			{
				AddMenuItem("������׺�","li",me);
				SendMenu(me);
			}
			else if(!strcmp(ask, "li") )
			{
				say("����۵�����С���Ѿ�������ѧ��Щ�书���ܲ����������ڽ�㣬�����ߣ������ұ�����������������ȥ�ˡ���",me);
				say("����۵�������ô��ʦֶ��ô���ĵ��ʼ����ã�Ī��Ҳ�ǿ�����������ò����",me);
				say("���æӦ��������ô�ᣬֻ����Ϊû�м���Сʦ�壬������ʰ��ˣ���",me);
				if(!me->query("xy/renwu7_31"))
				{
					me->set("xy/renwu7_31",1);//ѯ����׺�ȥ���¼�
					me->add("xy/��ɶ�",1);
				}
				SendMenu(me);
			}
			return 1;
		}
	}
	return CNpc::do_talk(me,ask);
}

static void do_die(CContainer * ob, LONG param1, LONG param2)
{
	destruct(ob);
}

virtual void die()
{
	if(querystr("owner1")[0])
	{
		CContainer * obj = environment();
		DTItemList * list = obj->Get_ItemList();  
		POSITION p = list->GetHeadPosition(); 
		while(p) 
		{ 
			CContainer * obj = list->GetNext(p);
			if(! obj->is_character()) continue; 
			CChar * target = (CChar *)obj;  
			if(!userp(target))	continue;
			if(EQUALSTR(querystr("owner1"),target->id(1)))
			{
				message_vision("\n$HIC����ۺ���˵�������ߣ��ø����ɵ�ʦֶ����Ȼ�����Դ�ʦ�壬���ǵ����ƣ���\n", this);
				target->del("xy/renwu7_pause");
				tell_object(target,"$HIR���������գ�����ʦ����ɽ���ѱչ������ɹ����������������5000�㡣");
				target->add("combat_exp",5000);
				destruct(this);
				break;
			}
		}
	}
	else
		CNpc::die();
}

NPC_END;




