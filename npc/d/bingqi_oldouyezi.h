//oldouyezi.h
//code by zwb
//12-16
//inherit F_CLEAN_UP;

NPC_BEGIN(CNBingQi_oldouyezi);


virtual void create()
{
		set_name("��ŷұ��","ou ye zi");

        set("gender", "����" );
        set("age", 73);
        set("long","ŷұ���ǵ���������ʦ�������Ľ������ޱȡ����������Ǯ̫�ٿ�Ҳ���С�һ��Ǯһ�ֻ�ô��");
        set("combat_exp", 200000);
        set("attitude", "friendly");
        set("rank_info/respect", "ŷұʦ��");
 	set("icon",old_man1);

        set_inquiry("����","��������˵��һ�����ң��������");
        set_inquiry("�۸�","����۸���...!�ٺ�,һ��һ������ۣ�һ��Ǯһ�ֻ�ô��");
		set("no_huan",1);
        
};


virtual int accept_object(CChar * player, CContainer * ob)
{
		char msg[255];

       if(player->query_temp("done_s"))
       {
          say(snprintf(msg,255,"ŷұ����ֵĿ���%s��:�㲻�����Լ��ı�����",player->name()),player);
		  SendMenu(player);
          return 0; 
	   }
       if( ob->query("money_id") && ob->query("value") >= 100000)
       {
			say(snprintf(msg,255," �ð�,%s������������, ���Եȣ�",player->query("name")),player);

			message_vision("ŷұ�ӽ�һ���ͭ��һ������������¯��������صķ��䣬����",player);
			message_vision("̰��������ͭ���顣..��ͭ����ͨ��͸��ʱŷұ��ʦ������������",player);
			message_vision("¯�У�����ƽ�Ͱ�����һ�Ṥ��ŷұ���ø�ǯ�г����飬�͵�",player);
			message_vision("��������һ��������ζ�ĺ�ɫҺ����..��..",player);
			message_vision("���..ƹ..ƹ..��....��....ƹ....ƹ...��....��...ƹ..��....��...ƹ...��.....",player);
			message_vision("..��....��....��....��....ŷұ�����쳤Ц�������壬������..��.....",player);
			message_vision("�����������ܴ�����ı�����ʲô��(name)��!",player);

			player->query_temp("marks/ouyezi");
			player->set_temp("marks/ouyezi",1);
			add_money(ob->query("value"));
			return 1;
        }
	   return 0;
}


virtual int handle_action(char *comm, CChar * player, char * arg)
{
	if(comm == "name")
		return do_name(player, arg);

	return 0;
}

int do_name(CChar * player,char * arg)
{
		
		CContainer * ownsword;
		char msg[255];
		CChar *npc=(CChar *)this;

		if(!player->query_temp("marks/ouyezi"))
        {
            return notify_fail("ŷұ������һ˦�֣�ʲô���������˼�Ҳ����");
        }

        if( !arg ) return notify_fail("ŷұ���ʵ��������������ܴ�����ı�����ʲô��(name)��");

        if( strlen(arg) > 20 )
			return notify_fail("ŷұ��˵���ۿ�����ô����ôд���£������һ��İɣ�");


        ownsword= load_item("ownsword");
        ownsword->set_name(arg);
        npc->say(snprintf(msg,255,"ֻ��ŷұ��ʦ������㳦�����ڱ��������ֻ��������������%s�������ɷ����ϸ�֣�ֱ���㿴��Ŀ�ɿڴ���",arg),player);		
        npc->say(" ���ˡ���ȥ�ɣ�˵������һ�ѽ�����..",player);

        ownsword->move(player);
        npc->say("�����Ž�����һ�£��������Ƹ��������Ǿ�����˫�����ա�",player);
        player->query_temp("done_s");
        player->set_temp("done_s",1);
        player->delete_temp("marks/ouyezi");

		return 1;
}

NPC_END;
