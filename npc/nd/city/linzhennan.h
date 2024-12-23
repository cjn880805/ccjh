// linzhennan.c 林震南
// zhangdongni  2001-07-18

NPC_BEGIN(CNcity_linzhennan);

virtual void create()
{
        set_name("林震西","lin zhenxi");
        set("gender", "男性");
        set("age", 45);
        set("long", "他就是「福威镖局」的总镖头－－林震西。\n");
        set("icon", young_man1);

        set("combat_exp", 30000);
        set("shen_type", 1);
        
        
        set("hp", 3000);
        set("max_hp", 3000);
        set("max_mp", 500);
        set("mp", 500);
        set("mp_foctor", 50);

        set_skill("force", 40);
        set_skill("sword", 50);
        set_skill("pixie-sword", 50);
        set_skill("unarmed", 50);
        set_skill("dodge", 50);
        set_skill("parry", 50);
        map_skill("parry", "pixie_sword");
        map_skill("sword", "pixie_sword");

        set_inquiry("向阳老宅" , "林震西说道：那是我从前在福建时住的家院，已经破败了。");
//        set_inquiry("福威镖局", "ask_fuwei");
 //               "远图公" : (: ask_yuantu :),
         set_inquiry( "林远图", "林震西大怒：小孩子这么没礼貌，直呼先人名讳！");
//                "辟邪剑法" : (: ask_pixie:),
//                "铜钱" : (: ask_tong:),
 //               "铜板" : (: ask_tong:),
  


        set_temp("apply/attack", 50);
        set_temp("apply/defense", 50);
        set_temp("apply/damage", 15);
        
//        carry_object("changjian")->wield();
//	carry_object("cloth")->wear();

/*

int ask_fuwei()
{
 say("林震南炫耀地说：我们林家三代走镖，一来仗着先祖远图公当年闯下的威名，二\n"
     "来靠著我们林家家传的玩艺儿不算含糊，这才有今日的局面，成为大江以南首屈\n"
     "一指的大镖局。江湖上提到『福威镖局』四字，谁都要翘起大拇指，说一声：『\n"
     "好福气！好威风！』哈哈，哈哈！\n");
 this_player()->set_temp("marks/林1", 1);
 return 1;
}

int ask_yuantu()
{
  if ((int)this_player()->query_temp("marks/林1")) {
 say("林震南磕一磕烟斗，说道：远图公是我的祖父，福威镖局是他一手创办的。当年\n"
     "祖父以七十二路辟邪剑法开创镖局，当真是打遍黑道无敌手。其时白道上英雄见\n"
     "他太过威风，也有去找他比试武艺的，青城派掌门余观主的师父长青子少年之时\n"
     "便在他辟邪剑法下输了几招。\n");
 this_player()->set_temp("marks/林2", 1);
 return 1;
  }
  else {
 say("林震南说道：远图公是我的祖父。\n");
 return 1;
  }
}

int ask_pixie()
{
  int p1, p2, p3, p4;

  if ((int)this_player()->query("passwd")) {
 say("林震南不悦地说道：我不是都告诉你了吗？我的剑法不及先祖。\n");
  }
  else if ((int)this_player()->query_temp("marks/林2")) {
 say("林震南一惊，说道：你怎么知道的？噢，我刚才说露嘴了。嗨，在下的功夫外人\n"
     "不知底细，其实及不上先祖。。\n");
 write("林震南顿一顿，接着对你低声说：先祖去世前，曾给家父留下");
 p1=random(4)+1;
 p2=random(4)+1;
 p3=random(4)+1;
 p4=random(4)+1;
 this_player()->set("passwd",p1*1000+p2*100+p3*10+p4);
 write(CHINESE_D->chinese_number(p1)+"千"+CHINESE_D->chinese_number(p2)+
       "百"+CHINESE_D->chinese_number(p3)+"十"+CHINESE_D->chinese_number(p4));
 write("个\n铜钱，我一直未解其中奥秘。\n");
  }
  else {
   message("vision",
   HIY "林震南勃然大怒，喝道：你也窥视我们林家的辟邪剑谱？！我跟你拼了！\n"
   NOR, environment(), this_object() );
   kill_ob(this_player());
  }
  this_player()->delete_temp("marks/林1");
  this_player()->delete_temp("marks/林2");
  return 1;
}

int ask_tong()
{
  int p, p1, p2, p3, p4;

  if (!(p=(int)this_player()->query("passwd"))) {
 say("林震南一脸讥笑的样子，说：怎么混到这一步了到处要钱？\n");
  }
  else {
 write("林震南低声说：先祖去世前，曾给家父留下");
 p1=(int)p/1000;
 p2=(int)(p-p1*1000)/100;
 p3=(int)(p-p1*1000-p2*100)/10;
 p4=(int)(p-p1*1000-p2*100-p3*10);
 write(CHINESE_D->chinese_number(p1)+"千"+CHINESE_D->chinese_number(p2)+
       "百"+CHINESE_D->chinese_number(p3)+"十"+CHINESE_D->chinese_number(p4));
 write("个\n铜钱，我一直未解其中奥秘。\n");
  }

  return 1;
}

*/
}
NPC_END;