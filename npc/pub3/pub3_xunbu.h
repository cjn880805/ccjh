//xunbu.h
//code by zwb
//12-25

NPC_BEGIN(CNpub3_xunbu);

virtual void create()
{
	 static char xunbuname[7][5]={"Ľ��","����","����","�Ϲ�","�Ϲ�","ŷ��","˾ͽ"};

	 set_name(xunbuname[random(7)],"xun bu");

	 set("icon", young_man2);
	 set("gender", "����" );
     set("age", 25);
     set("str", 45);
     set("cor", 50);
     set("cps", 35);
     set("int", 20);
     set("per", 20);
     set("kar", 15);
     set("long","Ѳ���������ֽý���ǿ����ɽ���޲��ŷ�ɥ����");
     set("status","patrol");
     set("CatchWho",0l);
     set("combat_exp", 500000);
     set("attitude", "heroism");
     set("chat_chance_combat", 40);


     set_inquiry("��¸","˵���ﻰ������̫ү��ƶ���������������µ�������û�����������������Ǯ�ɣ�");
     set_inquiry("нˮ","������үٺ��΢�������ǵ�������Ȼ������......");
     set_inquiry("Ǯ","˵ʵ�ڵģ���Ҳ��ҪǮ����Ҫ������ү֪���������ܻ�¸����Ҳ�ðǲ�Ƥ");

     set ("chat_chance",99);
/*     set ("chat_msg", ({
                      (:call_out,"patrol",0:),
                      }) );*/
     set("pursuer",1);
     set_skill("blade", 100);
     set_skill("parry", 90);
     set_skill("dodge", 70);

//     direction=GO;
     carry_object("gangdao")->wield();
     carry_object("cloth")->wear();
     add_money(30);
}

virtual char * combat_chat_msg(CChar * player)
{
	switch(random(4))
	{
	case 0:
		return "�����ʲô? ��������ȥ��������!?";
	case 1:
		return "��! ��Ȼ�ҵ��־ܲ�! ���췴��";
	case 2:
		return "Ѳ�����еĵ�Խ��Խ�죬����Ӧ�Ӳ�Ͼ��";
	case 3:
		return "������ˣ����ǹԹԵĸ����߰ɡ�";
	}
	return "";
}
/*
void init()
{
object catchwho,you,*npc;
object oldman,start_room;
int i,tmp;
catchwho=query("CatchWho");
you=this_player();
if (query("status")=="patrol")
   {
   if (!is_fighting()&&interactive(you)&&living(you))
      {
        npc=all_inventory(environment());
        i=sizeof(npc);
        while (i--) {
                if (npc[i]->query("id")=="gangster"&&!userp(npc[i]))
                        {
                        say(HIW "�����ʲô���ӣ�\n"+"��Ȼ"+
                                npc[i]->query("name")+
                               "Ҳ���ڴ�������գ�" NOR);
                        npc[i]->remove_all_enemy();
                        say("ȥ���ɣ���\n");
                        EMOTE_D->do_emote( npc[i],"fear");
                        kill_ob(npc[i]);
                        npc[i]->kill_ob(this_object());
                        }
                else if (npc[i]->query("title")=="Ұ��ɽկ��կ��"&&!userp(npc[i]))
                        {
                        say(HIR "�ߣ����°ܽ�������һ������Ҫ��ƽҰ��ɽկ��\n" NOR);
                        npc[i]->remove_all_enemy();
                        EMOTE_D->do_emote( npc[i],"fear");
                        kill_ob(npc[i]);
                        }
                }
        if (you->query("thief")&&random(10)<7)
           {
           say (HIR "���˰���ԭ��"+you->query("name")+
                        "�Ǹ�����! ����һ�˰�!\n" NOR);
           you->add("crime_lv",THIEF);
           you->add("thief",-1);
           if (!you->query("thief")) you->delete("thief");
           catchyou(you);
                return;
           }
        else
            if (you->query("marks/ǿ��")&&random(10)<9)
               {
               message_vision("$N����$n�ȵ������컯��֮�£����ȻҲ������ɱ�ˣ�
�������һ�ȥ�԰��ӣ�\n"
                +"˵�գ�$N������������$n�Ĳ����ϡ�\n",this_object(),you);
                        you->add("crime_lv",ROBBER);
                        you->add("marks/ǿ��",-1);
                        if (!you->query("marks/ǿ��")) you->delete("marks/ǿ��");
                catchyou(you);
                }
        }
   }
else if (query("status")=="catching")
   {
   catchyou(catchwho);
   message_vision(HIR "ֻ��$NͻȻ���������һ����������$n�Ĳ����ϡ�\n"NOR,
                this_object(),catchwho);
   }
else {
      if (objectp(catchwho=this_object()->query("CatchWho")))
        {
            if (BigWay[file_name(environment())][direction]==0)
                        {
        say("try to patrol\n");
                        start_room=find_object("/d/choyin/yamen.c");
                        oldman=find_object("/d/choyin/npc/judgeman.c");
                        oldman=present(oldman->query("id"),start_room);
                        write(oldman->query("id"));
                        catchwho->move(start_room);
                        move(start_room);
                        say("��ү���˷��Ѵ�����С��Ѳ��ȥ�ˡ�\n");
                        set("CatchWho",0);
                        direction=GO;
                        set("status","patrol");
                        move(find_object(query("startroom")+".c"));
                        patrol();
                        call_other(oldman,(:call_out,"settle_lawsuit",catchwho,2:));
                        return;
                        }
                }
        }
//add_action("do_go","go");
//add_action("do_quit","quit");
add_action("accept_bribery","bribe");
}

void patrol()
{
int i,on_way;
object *content,catchwho,start_room,crime,oldman;
string *bigwayname,where,dir;
bigwayname=keys(BigWay);
where=file_name(environment());
write("in patrol\n");
for (i=0;i<sizeof(bigwayname);i++)
    {
    if (where==bigwayname[i])
       {
       on_way=1;
       break;
       }
    else on_way=0;
    }
if (on_way)
   {
   if (this_object()->query("status")=="patrol")
      {
      if (!BigWay[where][direction]) direction=1-direction;
      }
   else if (this_object()->query("status")=="catching")
      {
      catchyou(catchwho);
      message_vision(HIR "ֻ��$NͻȻ���������һ����������$n�Ĳ�����"NOR,
                        this_object(),catchwho);
      }
   else
      {
        write("here???\n");
         }
  }
else
   {
   content=all_inventory(this_object());
   for (i=0;i<sizeof(content);i++)
       {
       if (content[i]->query("id")=="amulet")
                {
                if (!stringp(dir=content[i]->query("map")[where]))
                        {
                        move(start_room=find_object(query("startroom")+".c"));
                        if (objectp(crime=query("CatchWho")))
                                {
                                if (where==file_name(environment(crime)))
                                        crime->move(start_room);
                                }
                        }
                else mygo(dir);
          break;
          }
  }
  */
NPC_END;