//taohuatong.h  
//code by zwb
//12-25

NPC_BEGIN(CNpub3_taohuatong);


virtual void create()
{
	
	set_name("�һ�ͯ","tao hua tong");
	
	set("icon", boy2);
	set("gender", "����");
	set("age", 9);
	set("long","һ��������Ƥ��Сͯ��������ԧ��Ϫ�ı��ӡ�Ҳ���Ƥ��Ҳ�����ף����ǲ�ʱ�ж����硣");
	set("attitude", "friendly");
	set("combat_exp", 2500);
	set("per", 25);
	set_skill("dodge", 60);
	set("max_hp", 300);
	set("mp",10);
	set("max_mp",10);
	
//	carry_object("cloth")->wear();
	add_money(100);
}

/*
void init()
{
::init();
add_action("do_apply", "apply");
}

  int do_apply(string arg)
  {
  object me,spouse,officer,room;
  string str, partner, *householder,laotou;
  int i,j;
  me = this_player();
  officer = present("taohua tong", environment(me));
  laotou = officer->query("name");
  if(!arg)
  return notify_fail("��Ҫ����ʲô��\n");
  if(arg != "house" )
  return notify_fail("��Ҫ����ʲô��\n");
  if(!(me->query("couple/couple_id")))
  {
  message_vision(laotou+"�����ϳɵ�̾��̾����" +
  RANK_D->query_respect(me)
  +"���Ƕ���һ�ˣ���Ȼ��ң���ڡ��ο�����������\n", officer);
  return 3;
  }
  
	if(file_size("/data/playerhomes/h_"+me->query("id")+".o") != -1)
	{
	message_vision(laotou+"��Ƥ�ع��˹�"+me->query("name")+"��������Ц����" +
	RANK_D->query_respect(me) +"�����Ѿ����˷����𣿻�����ƭһ����\n",officer,me);
	return 1;
	}
	if((me->query("gender")) == "����")
	{       str = "����";
	}
	else
	{    str = "�ɷ�";
	}
	partner = me->query("couple/couple_id");
	if(file_size("/data/playerhomes/h_"+partner+".o") != -1)
	{
	message_vision(laotou+"��Ƥ�ع��˹�"+me->query("name")+"��������Ц����" +
	RANK_D->query_respect(me) +"�����ǼҲ����Ѿ����˷����𣿻�����ƭһ����\n",officer,me);
	return 1;
	}
	if(!(spouse = present(partner, environment(me))))
	{
	message_vision(laotou+"����"+me->query("name")+"ҡ��ҡͷ�����췿��ô����£�"+
	RANK_D->query_respect(me)+"���Ǻ���"+str+"һ�����ĺã�\n", officer, me);
	return notify_fail("�������"+str+"һ������\n");
	}
	if(!me->query_temp("rental_paid") && !spouse->query_temp("rental_paid"))
	return notify_fail(laotou+"����Ц��������ֻ��û�б��˵ķ���Ŷ��\n");
	message_vision(laotou+"Ц���еض�$N����Ȣ�ޡ��췿�����ӣ�����������Ү��\n", me);
	me->set_temp("is_applying_house",1);
	//   officer->set_temp("house_applied",1);
	
	  room=new("/d/taohuacun/obj/home");
	  room->set("file_name","h_"+me->query("id"));
	  room->set("home_host",({me->query("id")})+({partner}));
	  room->save();
	  
        message_vision("$N˵���������Ѿ������ˣ������ȥװ�ްɣ�\n",officer);
		
		  
			message_vision("$NЦ���еض�$n����ȡ�ޡ��췿�����ӣ�����������Ү��\n",officer,me);
			message_vision("$N˵������ȥ����鷿�ӣ�ȥȥ������" +
			RANK_D->query_respect(me)+
			"������Դ�Ƭ�̣��ɱ��߰���\n",officer);
			officer->move(filename);
			
			  return 1;
			  }
			  
				int accept_object(object who, object ob)
				{
				if(!ob->query("money_id"))
				return 0;
				if (ob->value()< 1000000)
				{
				if(who->query_temp("is_applying_house"))
				command("say "+RANK_D->query_respect(who)+"������ô�󷽡����ϱ�׼�����ûʡ�\n");
				else
				command("say "+RANK_D->query_respect(who)+"��ô����������͸����졣\n");
				}
				else
				{
				if(who->query_temp("is_applying_house"))
				command("say "+RANK_D->query_respect(who)+"������ô�󷽡����ϱ�׼�����ûʡ�\n");
				else
				{
				command("say "+RANK_D->query_respect(who)+"���������뷿�ӣ�����˵��\n");
				who->set_temp("rental_paid", 1);
				}
				}
				remove_call_out("destroying");
				call_out("destroying", 1, this_object(), ob);
				return 1;
				}
				
				  void destroying(object me, object obj)
				  {
				  destruct(obj);
				  return;
				  }
*/
NPC_END;